#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1e9+7;

long long modpow(long long a, long long e = MOD-2) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

class Solution {
public:
    int countBalancedPermutations(string num) {
        int n = num.size();
        vector<int> freq(10);
        for (char c : num) freq[c - '0']++;

        int E = (n + 1) / 2;
        int O = n / 2;
        int maxD = 9 * n;
        int M = 2 * maxD + 1;
        int off = maxD;

        vector<long long> fact(n + 1, 1), invf(n + 1, 1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invf[n] = modpow(fact[n]);
        for (int i = n; i > 0; --i) invf[i - 1] = invf[i] * i % MOD;

        auto C = [&](int a, int b) {
            if (b < 0 || b > a) return 0LL;
            return fact[a] * invf[b] % MOD * invf[a - b] % MOD;
        };

        vector<long long> dp((E + 1) * M), nxt((E + 1) * M);
        dp[off] = 1;
        int placed = 0;

        for (int d = 0; d < 10; ++d) {
            fill(nxt.begin(), nxt.end(), 0);
            int c = freq[d];
            for (int e_used = 0; e_used <= E; ++e_used) {
                for (int diff = -maxD; diff <= maxD; ++diff) {
                    long long ways = dp[e_used * M + diff + off];
                    if (!ways) continue;
                    int o_used = placed - e_used;
                    for (int x = 0; x <= c; ++x) {
                        int y = c - x;
                        if (e_used + x > E) break;
                        if (o_used + y > O) continue;
                        int nd = diff + d * (x - y);
                        long long comb = C(E - e_used, x) * C(O - o_used, y) % MOD;
                        nxt[(e_used + x) * M + nd + off] = (nxt[(e_used + x) * M + nd + off] + ways * comb) % MOD;
                    }
                }
            }
            placed += c;
            dp.swap(nxt);
        }

        return dp[E * M + off];
    }
};
