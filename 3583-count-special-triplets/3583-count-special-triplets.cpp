class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1000000007;
        unordered_map<int, long long> right;
        unordered_map<int, long long> left;
        
        for (int x : nums) right[x]++;
        
        long long ans = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            right[nums[j]]--;
            int x = nums[j];
            ans = (ans + (left[x * 2] * right[x * 2]) % MOD) % MOD;
            left[x]++;
        }
        
        return ans;
    }
};
