class Solution {
public:
    long long total = 0;
    long long best = 0;
    const int MOD = 1e9 + 7;

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long sum = root->val + left + right;
        best = max(best, sum * (total - sum));
        return sum;
    }

    int maxProduct(TreeNode* root) {
        total = dfs(root);
        dfs(root);
        return best % MOD;
    }
};
