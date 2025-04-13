class Solution {
public:
    int countGoodNumbers(long long n) {
        const long long mod = 1000000007;
        long long e1 = (n + 1) / 2;
        long long e2 = n / 2;
        long long res = modExp(5, e1, mod) % mod;
        res = (res * (modExp(4, e2, mod) % mod)) % mod;
        return (int)res;
    }
private:
    long long modExp(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while(exp > 0) {
            if(exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
};
