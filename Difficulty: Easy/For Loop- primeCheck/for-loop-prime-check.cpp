class Solution {
  public:
    string isPrime(int n) {
        if (n <= 1) return "No";  // 0 and 1 are not prime numbers
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return "No";  // divisible by a number other than 1 and itself
        }
        return "Yes";  // no divisors found, so it's prime
    }
};
