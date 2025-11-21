#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);
        for (int i = 0; i < n; ++i) {
            int c = s[i]-'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }
        vector<vector<int>> pref(26, vector<int>(n+1, 0));
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < 26; ++c) pref[c][i+1] = pref[c][i];
            pref[s[i]-'a'][i+1]++;
        }
        int ans = 0;
        for (int c = 0; c < 26; ++c) {
            if (first[c] < last[c]) {
                for (int m = 0; m < 26; ++m) {
                    if (pref[m][last[c]] - pref[m][first[c]+1] > 0) ++ans;
                }
            }
        }
        return ans;
    }
};
