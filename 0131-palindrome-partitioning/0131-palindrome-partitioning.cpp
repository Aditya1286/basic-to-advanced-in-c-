class Solution {
private:
    bool pali(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    void dfs(int i,int j,string s,vector<string> &partition){
        if(i==s.size()){
            res.push_back(partition);
            return;
        }
        if(j >= s.size())
            return;
        if(pali(s,i,j)){
            partition.push_back(s.substr(i,j-i+1));
            dfs(j+1,j+1,s,partition);
            partition.pop_back();
        }
        dfs(i,j+1,s,partition);
    }
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        dfs(0,0,s,partition);
        return res;
    }
};