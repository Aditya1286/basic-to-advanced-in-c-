class Solution {
public:
    string decodeString(string s) {
        string current;
        stack<pair<string,int>> st;
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if(c=='['){
                st.push({current,num});
                current="";
                num=0;
            }
            else if(c==']'){
                auto top = st.top();
                st.pop();
                string prev=top.first;
                int repeat=top.second;
                string temp;
                for(int i=0;i<repeat;i++){
                    temp+=current;
                }
                current=prev+temp;
            }
            else{
                current+=c;
            }
        }
        return current;
    }
};