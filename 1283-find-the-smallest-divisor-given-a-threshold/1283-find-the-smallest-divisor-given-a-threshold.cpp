class Solution {
public:
    int possible(vector<int> arr,int x){
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans=ans+ceil((double)arr[i]/(double)x);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<arr.size();i++){
            high=max(high,arr[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(arr,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};