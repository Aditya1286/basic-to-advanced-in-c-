class Solution {
private:
    void dfs(int index,string str,string digits){
        if(index>=digits.size()){
            res.push_back(str);
            return;
        }
        string st=mp[digits[index]-'0'];
        for(char c:st){
            str.push_back(c);
            dfs(index+1,str,digits);
            str.pop_back();
        }
    }
public:
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
    vector<string> letterCombinations(string digits) {
        string str ="";
        dfs(0,str,digits);
        return res;
    }
};