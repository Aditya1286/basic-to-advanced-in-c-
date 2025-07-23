// User function Template for C++

class Solution {
  public:
   void solve(int n,string &curr,vector<string> &res){
        if(n==0){
            res.push_back(curr);
            return;
        }
        curr.push_back('0');
        solve(n-1,curr,res);
        curr.pop_back();
        if(curr.size()==0||curr.back()=='0'){
            curr.push_back('1');
            solve(n-1,curr,res);
            curr.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int n) {
        vector<string> res;
      string curr;
      solve(n,curr,res);
      return res; 
    }
};