/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int left,int right){
        if(left>right)return nullptr;
        int nodevalue=preorder[preo++];
        TreeNode* root=new TreeNode(nodevalue);
        int mid=mp[nodevalue];
        root->left=build(preorder,inorder,left,mid-1);
        root->right=build(preorder,inorder,mid+1,right);
        return root;
    }
public:
    unordered_map<int,int> mp;
    int preo=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,n-1);
    }
};