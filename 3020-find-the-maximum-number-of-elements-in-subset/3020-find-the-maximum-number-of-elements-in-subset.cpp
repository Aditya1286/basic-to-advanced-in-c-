class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int x : nums) {
            count[x]++;
        }
        int res = 0;
        for (auto& [num, freq] : count) {
            long long key = num;
            int total = 0;
            if (key == 1) {
                total = (freq % 2 == 1) ? freq : freq - 1;
            } else {
                while (count[key] >= 2 && count.count(key * key)) {
                    total += 2;
                    key = key * key;
                }
                total += 1;
            }
            res = max(res, total);
        }
        return res;
    }
};