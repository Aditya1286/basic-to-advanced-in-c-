class Solution {
    static const int MOD = 1e9+7;
    long long modexp(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }
public:
    int countGoodArrays(int n, int m, int k) {
        if (k > n-1) return 0;
        vector<long long> fact(n), invfact(n);
        fact[0] = 1;
        for (int i = 1; i < n; ++i) fact[i] = fact[i-1] * i % MOD;
        invfact[n-1] = modexp(fact[n-1], MOD-2);
        for (int i = n-1; i > 0; --i) invfact[i-1] = invfact[i] * i % MOD;
        auto comb = [&](int a, int b) {
            if (b < 0 || b > a) return 0LL;
            return fact[a] * invfact[b] % MOD * invfact[a-b] % MOD;
        };
        long long ways = comb(n-1, k);
        ways = ways * m % MOD;
        ways = ways * modexp(m-1, n-k-1) % MOD;
        return (int)ways;
    }
};
