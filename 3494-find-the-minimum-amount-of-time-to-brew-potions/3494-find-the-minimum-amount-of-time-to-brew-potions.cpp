class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> S(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += skill[i];
            S[i] = sum;
        }
        if (m == 0) return 0; 
        vector<long long> t(m, 0);
        t[0] = 0;
        for (int j = 1; j < m; ++j) {
            long long maxv = 0;
            for (int i = 0; i < n; ++i) {
                long long Si = S[i];
                long long Sim1 = (i > 0 ? S[i-1] : 0LL);
                long long val = Si * 1LL * mana[j-1] - Sim1 * 1LL * mana[j];
                if (val > maxv) maxv = val;
            }
            if (maxv < 0) maxv = 0; 
            t[j] = t[j-1] + maxv;
        }
        long long ans = t[m-1] + S[n-1] * 1LL * mana[m-1];
        return ans;
    }
};
