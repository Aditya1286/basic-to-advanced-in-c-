class Solution {
private:

    vector<string> res;

    unordered_map<int, string> mp = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    void bfs(int index, string str, string digits) {

        if (index >= digits.size()) {
            res.push_back(str);
            return;
        }

        string ch = mp[digits[index] - '0'];

        for (char c : ch) {
            bfs(index + 1, str + c, digits);
        }
    }

public:

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return res;

        bfs(0, "", digits);

        return res;
    }
};