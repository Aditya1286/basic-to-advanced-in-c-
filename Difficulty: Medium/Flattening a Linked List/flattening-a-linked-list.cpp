class Solution {
  public:
    Node* merge(Node* a, Node* b) {
        Node* dummy = new Node(-1);
        Node* tail = dummy;

        while (a && b) {
            if (a->data < b->data) {
                tail->bottom = a;
                a = a->bottom;
            } else {
                tail->bottom = b;
                b = b->bottom;
            }
            tail = tail->bottom;
        }

        if (a) tail->bottom = a;
        else tail->bottom = b;

        return dummy->bottom;
    }

    Node* flatten(Node* root) {
        if (!root || !root->next) return root;

        root->next = flatten(root->next);
        root = merge(root, root->next);

        return root;
    }
};
