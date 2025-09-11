class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(TreeNode* node, vector<int>& ans) {
        if (node == nullptr)
            return;

        ans.push_back(node->val);    
        helper(node->left, ans);     
        helper(node->right, ans);    
    }
};
