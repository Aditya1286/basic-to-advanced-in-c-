class Solution {
  public:
    int maxkadane(vector<int> & arr){
        int ans=arr[0];
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            maxi=max(maxi+arr[i],arr[i]);
            ans=max(ans,maxi);
        }
        return ans;
    }
    int minkadane(vector<int> & arr){
        int ans=arr[0];
        int mini=arr[0];
        for(int i=1;i<arr.size();i++){
            mini=min(mini+arr[i],arr[i]);
            ans=min(ans,mini);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int> &arr) {
        int withoutcir=maxkadane(arr);
        int minimum=minkadane(arr);
        int sum=0;
        for(int i=0;i<arr.size();i++) sum=sum+arr[i];
        int withcir=sum-minimum;
        if (withoutcir < 0) return withoutcir;
        return max(withoutcir,withcir);
    }
};