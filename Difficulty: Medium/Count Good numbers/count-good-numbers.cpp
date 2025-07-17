class Solution {
public:
    const long long mod = 1e9 + 7;

    long long mypow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long N) {
        long long even = (N + 1) / 2;
        long long odd = N / 2;
        long long part1 = mypow(5, even);
        long long part2 = mypow(4, odd);
        return (part1 * part2) % mod;
    }
};
