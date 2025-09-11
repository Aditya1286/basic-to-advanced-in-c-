// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        vector<int> ans;
        helper(node,ans);
        return ans;
    }
    void helper(Node* node,vector<int>& ans){
        if(node==NULL){
            return;
        }
        helper(node->left,ans);
        helper(node->right,ans);
        ans.push_back(node->data);
    }
};