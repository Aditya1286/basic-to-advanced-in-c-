class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string current="";
        int n=path.size();
        for(int i=0;i<n;i++){
            if(path[i]=='/'){
                if(current=="" || current==".");
                else if(current==".."){
                    if(!st.empty())st.pop();
                }
                else{
                    st.push(current);
                }
                current="";
            }
            else{
                current+=path[i];
            }
        }
        //last token 
        if(current==".."){
            if(!st.empty())st.pop();
        }
        else if(current!="" && current!="."){
            st.push(current);
        }
        vector<string> temp;
        string ans;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(string str:temp){
            ans += "/" + str;
        }
        return ans==""?"/":ans;
    }
};