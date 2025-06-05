class Solution {
public:
    long long sumOfDivisors(int n) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += (n / i) * 1LL * i;
        }
        return sum;
    }
};