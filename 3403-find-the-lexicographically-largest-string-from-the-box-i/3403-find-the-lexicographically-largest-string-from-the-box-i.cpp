#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;

        int L = n - numFriends + 1;
        char mx = *max_element(word.begin(), word.end());
        
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (word[i] != mx) continue;
            int takeLen = min(L, n - i);
            string candidate = word.substr(i, takeLen);
            if (candidate > ans) {
                ans = candidate;
            }
        }
        return ans;
    }
};
