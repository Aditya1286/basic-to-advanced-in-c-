class Solution {
  public:
    int maxDepth(string s) {
        int res=0;
        int current=0;
        for(char& ch:s){
            if(ch=='('){
                current++;
                res=max(res,current);
            }
            if(ch==')'){
                current--;
            }
        }
        return res;
    }
};