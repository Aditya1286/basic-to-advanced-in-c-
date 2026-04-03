class Solution {
private:
    void solve(vector<int> nums, vector<int> subset, vector<vector<int>>& ans){
        if(nums.size() == 0){
            ans.push_back(subset);
            return;
        }

        vector<int> sub1 = subset;
        vector<int> sub2 = subset;
        sub2.push_back(nums[0]);

        vector<int> remaining(nums.begin() + 1, nums.end());

        solve(remaining, sub1, ans); 
        solve(remaining, sub2, ans); 
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(nums, subset, ans);
        return ans;
    }
};