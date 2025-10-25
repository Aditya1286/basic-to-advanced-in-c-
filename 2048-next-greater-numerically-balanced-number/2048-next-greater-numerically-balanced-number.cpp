class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<long long> nums;
        for (int mask = 1; mask < (1 << 9); ++mask) {
            int sum = 0;
            for (int d = 1; d <= 9; ++d) if (mask & (1 << (d - 1))) sum += d;
            if (sum > 9) continue;
            vector<int> digits;
            for (int d = 1; d <= 9; ++d) if (mask & (1 << (d - 1)))
                for (int k = 0; k < d; ++k) digits.push_back(d);
            sort(digits.begin(), digits.end());
            do {
                long long val = 0;
                for (int x : digits) val = val * 10 + x;
                nums.push_back(val);
            } while (next_permutation(digits.begin(), digits.end()));
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (long long v : nums) if (v > n) return (int)v;
        long long num = (long long)n + 1;
        while (true) {
            int x = num;
            int cnt[10] = {0};
            while (x > 0) { cnt[x % 10]++; x /= 10; }
            bool ok = true;
            for (int d = 1; d <= 9; ++d) if (cnt[d] && cnt[d] != d) { ok = false; break; }
            if (ok) return (int)num;
            ++num;
        }
    }
};
