class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> res;
        long long ans = 1;
        res.push_back(1);
        for (int i = 1; i < n; i++) {
            ans = ans * (n - i);
            ans = ans / i;
            res.push_back((int)ans);
        }
        return res;
    }
};
