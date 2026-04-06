class Solution {
private:
    void solve(vector<int>& nums,int index,vector<vector<int>>& res){
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int> unique_set;
        for(int i=index;i<nums.size();i++){
            if(unique_set.find(nums[i])!=unique_set.end())continue;
            unique_set.insert(nums[i]);
            swap(nums[i],nums[index]);
            solve(nums,index+1,res);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums,0,res);
        return res;
    }
};