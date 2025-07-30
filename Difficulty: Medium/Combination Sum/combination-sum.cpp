// User function template for C++

class Solution {
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    void sum(int index,int n,int target,vector<int>& ds,vector<int>& arr,vector<vector<int>>& res){
        if(index==n){
            if(target==0){
                res.push_back(ds);
            }
            return;
        }
        if(arr[index]<=target){
            ds.push_back(arr[index]);
            sum(index,n,target-arr[index],ds,arr,res);
            ds.pop_back();
        }
        sum(index+1,n,target,ds,arr,res);
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sum(0,arr.size(),target,ds,arr,res);
        return res;
    }
};