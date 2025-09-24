class Solution {
  public:
    int isSumProperty(Node *root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) 
            return 1;
        
        int leftVal = (root->left) ? root->left->data : 0;
        int rightVal = (root->right) ? root->right->data : 0;
        
        if (root->data == leftVal + rightVal 
            && isSumProperty(root->left) 
            && isSumProperty(root->right)) 
            return 1;
        
        return 0;
    }
};
