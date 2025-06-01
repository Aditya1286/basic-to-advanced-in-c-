class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto comb = [](long long n) {
            return n < 0 ? 0LL : (n + 2) * (n + 1) / 2;
        };
        
        long long total = comb(n);
        
        for (int i = 1; i <= 3; i++) {
            for (int mask = 0; mask < (1 << 3); ++mask) {
                if (__builtin_popcount(mask) != i) continue;

                int sumLimit = 0;
                for (int j = 0; j < 3; ++j) {
                    if (mask & (1 << j)) sumLimit += limit + 1;
                }
                total += (i % 2 == 1 ? -1 : 1) * comb(n - sumLimit);
            }
        }
        
        return total;
    }
};
