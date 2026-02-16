class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &c : tokens){
            if(c=="+"){
                int top1=st.top();
                st.pop();
                int top2=st.top();
                st.pop();
                st.push(top1+top2);
            }
            else if(c=="-"){
                int top1=st.top();
                st.pop();
                int top2=st.top();
                st.pop();
                st.push(top2-top1);
            }
            else if(c=="*"){
                int top1=st.top();
                st.pop();
                int top2=st.top();
                st.pop();
                st.push(top1*top2);
            }
            else if(c=="/"){
                int top1=st.top();
                st.pop();
                int top2=st.top();
                st.pop();
                st.push(top2/top1);
            }
            else{
                int num = stoi(c);
                st.push(num);
            }
        }
        return st.top();
    }
};