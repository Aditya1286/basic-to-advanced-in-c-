class Solution {
  private:
    bool isleaf(Node* node) {
        if (!node) return false;
        return (node->left == NULL) && (node->right == NULL);
    }

    void leftbound(Node* root, vector<int> &res) {
        Node* curr = root->left;
        while (curr) {
            if (!isleaf(curr)) res.push_back(curr->data);
            if (curr->left != NULL) curr = curr->left;
            else curr = curr->right;
        }
    }

    void rightbound(Node* root, vector<int> &res) {
        Node* curr = root->right;
        vector<int> ds;
        while (curr) {
            if (!isleaf(curr)) ds.push_back(curr->data);
            if (curr->right != NULL) curr = curr->right;
            else curr = curr->left;
        }
        reverse(ds.begin(), ds.end());
        res.insert(res.end(), ds.begin(), ds.end());
    }

    void leaf(Node* root, vector<int> &res) {
        if (!root) return;
        if (isleaf(root)) {
            res.push_back(root->data);
            return;
        }
        leaf(root->left, res);
        leaf(root->right, res);
    }

  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        if (!isleaf(root)) ans.push_back(root->data);
        leftbound(root, ans);
        leaf(root, ans);
        rightbound(root, ans);
        return ans;
    }
};
