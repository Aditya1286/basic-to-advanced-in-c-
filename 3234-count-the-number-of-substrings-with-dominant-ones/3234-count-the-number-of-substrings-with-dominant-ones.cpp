class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zero;
        for (int i = 0; i < n; i++) if (s[i] == '0') zero.push_back(i);
        vector<int> pre1(n + 1, 0);
        for (int i = 0; i < n; i++) pre1[i + 1] = pre1[i] + (s[i] == '1');
        long long ans = 0;
        int Z = zero.size();
        int maxK = 200;
        for (int l = 0; l < n; l++) {
            int zidx = lower_bound(zero.begin(), zero.end(), l) - zero.begin();
            for (int k = 0; k <= maxK; k++) {
                if (zidx + k > Z) break;
                int L = (k == 0 ? l : zero[zidx + k - 1]);
                int R = (zidx + k < Z ? zero[zidx + k] - 1 : n - 1);
                if (L > R) continue;
                if (k == 0) {
                    ans += (R - L + 1);
                } else {
                    int lo = L, hi = R, pos = -1;
                    int need = k * k;
                    while (lo <= hi) {
                        int mid = lo + (hi - lo) / 2;
                        int ones = pre1[mid + 1] - pre1[l];
                        if (ones >= need) { pos = mid; hi = mid - 1; }
                        else lo = mid + 1;
                    }
                    if (pos != -1) ans += (R - pos + 1);
                }
            }
        }
        return (int)ans;
    }
};
