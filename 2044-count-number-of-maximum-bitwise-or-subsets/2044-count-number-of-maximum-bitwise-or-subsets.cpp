class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0, count = 0;
        function<void(int, int)> dfs = [&](int i, int currOr) {
            if (i == n) {
                if (currOr == maxOr) count++;
                return;
            }
            dfs(i + 1, currOr | nums[i]);
            dfs(i + 1, currOr);
        };
        for (int num : nums) {
            maxOr |= num;
        }
        dfs(0, 0);
        return count;
    }
};
