class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> myset(nums);
        return myset.size()==nums.size();
    }
};