class Solution {
public:
    int asd(vector<int>arr,int n){
        int painter=1;
        int nowork=0;
        for(int i=0;i<arr.size();i++){
            if(nowork+arr[i]<=n){
                nowork+=arr[i];
            }
            else{
                painter++;
                nowork=arr[i];
            }
        }
        return painter;
    }
    int splitArray(vector<int>& arr, int k) {
        int low=0;
        int high=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            low=max(low,arr[i]);
            high+=arr[i];
        }
        if(k>n)return -1;
        while(low<=high){
            int mid=(low+high)/2;
            int count=asd(arr,mid);
            if(count>k)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};