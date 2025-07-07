class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        if (!head) return nullptr;
        Node* cur = head;
        while (cur) {
            Node* c = new Node(cur->data);
            c->next = cur->next;
            cur->next = c;
            cur = c->next;
        }
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node* dummy = new Node(0);
        Node* tail = dummy;
        cur = head;
        while (cur) {
            Node* c = cur->next;
            cur->next = c->next;
            tail->next = c;
            tail = c;
            cur = cur->next;
        }
        return dummy->next;
    }
};
