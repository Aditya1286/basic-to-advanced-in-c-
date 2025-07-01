class Solution {
  public:
    string removeOuter(string& str) {
        vector<char> chars(str.begin(), str.end());
        int count=0;
        string s="";
        for(int i=0;i<str.size();i++){
            if(chars[i]=='('){
                if(count>0){
                    s+=chars[i];
                }
                count++;
            }
            else{
                count--;
                if(count>0)s+=chars[i];
            }
        }
        return s;
    }
};