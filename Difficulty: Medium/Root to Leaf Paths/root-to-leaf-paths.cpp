/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void res(Node* root,vector<vector<int>> &ans,vector<int> v){
        if(root==NULL){
            return;
        }
        v.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(v);
        }
        res(root->left,ans,v);
        res(root->right,ans,v);
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> v;
        res(root,ans,v);
        return ans;
    }
};