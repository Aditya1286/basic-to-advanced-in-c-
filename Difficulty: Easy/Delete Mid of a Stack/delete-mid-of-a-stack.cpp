class Solution {
  public:
    void del(stack<int>&st,int k){
        if(k==1){
            st.pop();
            return;
        }
        int top=st.top();
        st.pop();
        del(st,k-1);
        st.push(top);
    }
    void deleteMid(stack<int>& st) {
        if(st.empty())return ;
        int n=st.size();
        int k=n/2+1;
        del(st,k);
    }
};