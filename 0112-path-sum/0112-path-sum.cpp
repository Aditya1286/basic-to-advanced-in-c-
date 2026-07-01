class Solution {
private:
    bool summ(TreeNode* root, int target, int sum) {

        if(root == nullptr)
            return false;

        sum += root->val;

        if(root->left == nullptr && root->right == nullptr)
            return sum == target;

        return summ(root->left, target, sum) ||
               summ(root->right, target, sum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return summ(root, targetSum, 0);
    }
};