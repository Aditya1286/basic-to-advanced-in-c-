class Solution {
public:
    void asd(vector<string> &res,int open ,int close,int n,string& stack){
        if(open==close && open==n){
            res.push_back(stack);
            return;
        }
        if(open<n){
            stack+='(';
            asd(res,open+1,close,n,stack);
            stack.pop_back();
        }
        if(close<open){
            stack+=')';
            asd(res,open,close+1,n,stack);
            stack.pop_back();
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string st="";
        asd(res,0,0,n,st);
        return res;
    }
};