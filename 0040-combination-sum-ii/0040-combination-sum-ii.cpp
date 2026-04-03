class Solution {
private:
    void solve(vector<int>& nums,int index,int target,vector<int>&subset,vector<vector<int>>&res){
        if(target==0){
            res.push_back(subset);
            return ;
        }
        if(index>=nums.size() || target<0){
            return;
        }
        subset.push_back(nums[index]);
        solve(nums,index+1,target-nums[index],subset,res);
        subset.pop_back();
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        solve(nums,index+1,target,subset,res);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target,subset,res);
        return res;
    }
};