class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        if(s1.size()!=s2.size()){
            return false;
        }
        map<char,char> m1,m2;
        for(int i=0;i<s1.size();i++){
            if(m1.find(s1[i])!=m1.end()){
                if(m1[s1[i]]!=s2[i]){
                    return false;
                }
            }
            else if(m2.find(s2[i])!=m2.end()){
                if(m2[s2[i]]!=s1[i]){
                    return false;
                }
            }
            else{
                m1[s1[i]]=s2[i];
                m2[s2[i]]=s1[i];
            }
        }
        return true;
    }
};