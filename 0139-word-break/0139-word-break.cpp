class Solution {
public:
    bool solve(int start, string &s, unordered_set<string> &wd, vector<int> &dp) {
        if (start == s.size()) return true;
        if (dp[start] != -1) return dp[start];

        for (int end = start; end < s.size(); ++end) {
            if (wd.count(s.substr(start, end - start + 1))) {
                if (solve(end + 1, s, wd, dp)) 
                    return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wd(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, wd, dp);
    }
};
