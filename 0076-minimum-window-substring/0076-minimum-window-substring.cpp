class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";
        vector<int> need(128, 0);
        for (char c : t) need[c]++;
        int required = t.size();
        int l = 0, bestLen = INT_MAX, bestL = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            char c = s[r];
            if (need[c] > 0) required--;
            need[c]--;
            while (required == 0) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }
                char cl = s[l];
                need[cl]++;
                if (need[cl] > 0) required++;
                l++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};
