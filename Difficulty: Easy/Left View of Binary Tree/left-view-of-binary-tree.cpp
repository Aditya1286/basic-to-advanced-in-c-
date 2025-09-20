/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
  vector<int> ds;
    void leftview(Node* root,int level){
            if(root==nullptr){
                return ;
            }
            if(level==ds.size()){
                ds.push_back(root->data);
            }
            leftview(root->left,level+1);
            leftview(root->right,level+1);
    }
    vector<int> leftView(Node *root) {
        leftview(root,0);
        return ds;
        
    }
};