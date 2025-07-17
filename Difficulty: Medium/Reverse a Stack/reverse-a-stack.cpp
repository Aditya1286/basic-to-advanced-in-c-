// User function Template for C++

class Solution {
  public:
  void insert(stack<int> &st, int ele) {
    if (st.empty()) {
        st.push(ele);
        return;
    }
    int top = st.top();
    st.pop();
    insert(st, ele);
    st.push(top);
}

    void Reverse(stack<int> &st) {
        if(st.empty())return ;
        int top=st.top();
        st.pop();
        Reverse(st);
        insert(st,top);
    }
};