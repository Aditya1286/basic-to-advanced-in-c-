// User function template for C++

class Solution {
  public:
    int asd(vector<int> arr,int n){
        int painter=1;
        int work=0;
        for(int i=0;i<arr.size();i++){
            if(work+arr[i]<=n){
                work+=arr[i];
            }
            else{
                painter++;
                work=arr[i];
            }
        }
        return painter;
    }
    int minTime(vector<int>& arr, int k) {
        int low=0;
        int high=0;
        int n=arr.size();
        for(int i:arr){
            low=max(low,i);
            high+=i;
        }
        while(low<=high){
            int mid=(low+high)/2;
            int count=asd(arr,mid);
            if(count>k)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};