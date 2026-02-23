/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* root) {
        if(root==nullptr)return;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            auto top=st.top();
            st.pop();
            swap(top->left,top->right);
            if(top->left)st.push(top->left);
            if(top->right)st.push(top->right);
        }
    }
};