// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int key) {
        int floor = -1;
    while (root) {
        if (root->data == key) {
            floor = root->data;
            return floor;
        }
        if (key > root->data) {
            floor = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
    }
};