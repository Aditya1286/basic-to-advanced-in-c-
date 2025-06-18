class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        vector<long long> ass;
        return asd(ass, n, 1, 1);
    }

    vector<long long> asd(vector<long long> ass, long long n, long long count, long long fact) {
        if (fact > n) return ass;
        ass.push_back(fact);
        return asd(ass, n, count + 1, fact * (count + 1));
    }
};