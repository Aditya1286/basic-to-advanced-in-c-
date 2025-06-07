class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<bool> deleted(n, false);
        vector<vector<int>> pos(26);
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                 for (int c = 0; c < 26; ++c) {
                    if (!pos[c].empty()) {
                        int idx = pos[c].back();
                        pos[c].pop_back();
                        deleted[idx] = true;
                        break;
                    }
                }
                deleted[i] = true;
            } else {
                pos[s[i] - 'a'].push_back(i);
            }
        }
        
        string result;
        result.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (!deleted[i] && s[i] != '*')
                result += s[i];
        }
        return result;
    }
};
