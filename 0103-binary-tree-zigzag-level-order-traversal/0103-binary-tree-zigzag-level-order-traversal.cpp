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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*>nq;
        nq.push(root);
        bool flag=true;
        while(!nq.empty()){
            int size=nq.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node=nq.front();
                nq.pop();
                level.push_back(node->val);
                if(node->left!=nullptr)nq.push(node->left);
                if(node->right!=nullptr)nq.push(node->right);
            }
            if(flag==false){
                reverse(level.begin(),level.end());
            }
            flag=!flag;
            ans.push_back(level);
        }
        return ans;
    }
};