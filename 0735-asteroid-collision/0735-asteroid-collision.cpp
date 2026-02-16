class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int &ast:asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top()>0 && ast<0){
                if(abs(ast)>st.top()){
                    st.pop();
                    continue;
                }
                else if(abs(ast)==st.top()){
                    destroyed = true;
                    st.pop();
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                st.push(ast);
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size()-1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};