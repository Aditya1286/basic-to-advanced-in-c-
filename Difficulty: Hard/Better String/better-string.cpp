// User function Template for C++

// class Solution {
// public:
//     void count_subsequence(int index, vector<string>& result, string current, string str) {
//         if (index == str.length()) {
//             result.push_back(current);
//             return;
//         }
//         count_subsequence(index + 1, result, current + str[index], str);
//         count_subsequence(index + 1, result, current, str);
//     }

//     string betterString(string &s1, string &s2) {
//         vector<string> res1;
//         vector<string> res2;
//         count_subsequence(0, res1, "", s1);
//         count_subsequence(0, res2, "", s2);

//         set<string> str1(res1.begin(), res1.end());
//         set<string> str2(res2.begin(), res2.end());

//         if (str1.size() >= str2.size()) {
//             return s1;
//         } else {
//             return s2;
//         }
//     }
// };
class Solution {
public:
    int countDistinctSubsequences(string& s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        unordered_map<char, int> last;

        for (int i = 1; i <= n; i++) {
            char ch = s[i - 1];
            dp[i] = (2LL * dp[i - 1]) % 1000000007;

            if (last.find(ch) != last.end()) {
                dp[i] = (dp[i] - dp[last[ch] - 1] + 1000000007) % 1000000007;
            }

            last[ch] = i;
        }

        return dp[n];
    }

    string betterString(string &s1, string &s2) {
        int count1 = countDistinctSubsequences(s1);
        int count2 = countDistinctSubsequences(s2);
        return (count1 >= count2) ? s1 : s2;
    }
};
