class Solution {
  public:
    int longestCommonPrefix(string str1, string str2) {
        int n = str1.size();
        for (int len = n; len > 0; len--) {
            string prefix = str1.substr(0, len);
            if (str2.find(prefix) != string::npos) {
                return len;
            }
        }
        return 0;
    }
};
