class Solution {
  public:
    static const int MAXN = 200000;
    static vector<int> spf;
    static bool built;

    static void sieve() {
        if (built) return;
        spf.assign(MAXN + 1, 0);
        for (int i = 0; i <= MAXN; ++i) spf[i] = i;
        for (int i = 2; i * i <= MAXN; ++i) if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) if (spf[j] == j) spf[j] = i;
        }
        built = true;
    }

    vector<int> findPrimeFactors(int N) {
        sieve();
        vector<int> res;
        while (N > 1) {
            int p = spf[N];
            res.push_back(p);
            N /= p;
        }
        return res;
    }
};

vector<int> Solution::spf;
bool Solution::built = false;
