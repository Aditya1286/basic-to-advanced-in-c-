class Solution {
  public:
    void generate(int index, string &s, string current, vector<string> &result) {
        if (index == s.length()) {
            if (!current.empty())
                result.push_back(current);
            return;
        }
        generate(index + 1, s, current + s[index], result);
        generate(index + 1, s, current, result);
    }

    vector<string> AllPossibleStrings(string s) {
        vector<string> result;
        generate(0, s, "", result);
        sort(result.begin(), result.end());
        return result;
    }
};
