class BSTIterator {
    stack<TreeNode*> st;
    bool forward;
public:
    BSTIterator(TreeNode* root, bool isForward) : forward(isForward) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top(); st.pop();
        if (forward) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
    
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = forward ? node->left : node->right;
        }
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, true), r(root, false);
        int i = l.next(), j = r.next();
        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) {
                if (l.hasNext()) i = l.next();
                else return false;
            } else {
                if (r.hasNext()) j = r.next();
                else return false;
            }
        }
        return false;
    }
};
