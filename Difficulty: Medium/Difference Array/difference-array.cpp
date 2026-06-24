class Solution {
  public:
    vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        int n=arr.size();
        vector<int> nums(n,0);
        for(int i=0;i<opr.size();i++){
            int l=opr[i][0];
            int r=opr[i][1];
            int v=opr[i][2];
            if(r+1<n){
                nums[r+1]-=v;
            }
            nums[l]+=v;
        }
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<n;i++){
            arr[i]+=nums[i];
        }
        return arr;
    }
};