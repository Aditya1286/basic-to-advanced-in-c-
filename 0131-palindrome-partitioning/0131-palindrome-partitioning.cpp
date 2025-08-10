class Solution {
public:
vector<vector<string>> result;
    bool palindrome(string s, int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int index,string s,vector<string>& path){
        if(index==s.length()){
            result.push_back(path);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(palindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,s,path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
       vector<string> path;
       solve(0,s,path);
       return result;
    }
};