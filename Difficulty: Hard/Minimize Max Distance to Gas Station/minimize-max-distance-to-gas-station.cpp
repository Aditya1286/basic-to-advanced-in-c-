class Solution {
  public:
    bool check(vector<int> arr,double c,int k){
        int count=0;
        for(int i=1;i<arr.size();i++){
            double dist=(double)arr[i]-arr[i-1];
            if(dist<=c)continue;
            else{
                count+=(int)dist/c;
            }
        }
        return count<=k;
    }
    double findSmallestMaxDist(vector<int> &arr, int k) {
        double low=0.0;
        double high=0.0;
        for(int i=1;i<arr.size();i++){
            double dis=(double)arr[i]-arr[i-1];
            high=max(high,dis);
        }
        while(high-low>1e-6){
            double mid=(high+low)/2.0;
            if(check(arr,mid,k))high=mid;
            else low=mid;
        }
        return high;
    }
};