#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canRepeatK(const string &s, const string &t, int k) {
        int idx = 0, repeats = 0;
        for (char c : s) {
            if (c == t[idx]) {
                idx++;
                if (idx == (int)t.size()) {
                    repeats++;
                    idx = 0;
                    if (repeats == k) return true;
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;
        vector<char> letters;
        for (int i = 25; i >= 0; --i)
            if (freq[i] >= k)
                letters.push_back('a' + i);
        string best;
        function<void(const string&)> dfs = [&](const string &cur) {
            for (char c : letters) {
                string nxt = cur + c;
                if (canRepeatK(s, nxt, k)) {
                    if (nxt.size() > best.size() || (nxt.size() == best.size() && nxt > best))
                        best = nxt;
                    dfs(nxt);
                }
            }
        };
        dfs("");
        return best;
    }
};
