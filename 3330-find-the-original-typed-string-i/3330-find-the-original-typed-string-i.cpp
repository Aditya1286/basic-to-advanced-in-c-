class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        int n = word.length();
        for (int i = 1, len = 1; i <= n; ++i) {
            if (i < n && word[i] == word[i - 1]) {
                len++;
            } else {
                if (len > 1) count += len - 1;
                len = 1;
            }
        }
        return count;
    }
};
