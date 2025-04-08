class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        
        while (true) {
            unordered_set<int> seen(nums.begin(), nums.end());
            if (seen.size() == nums.size()) return ops;
            
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            ops++;
        }
        
        return ops;
    }
};
