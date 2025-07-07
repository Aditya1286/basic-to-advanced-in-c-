class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if (x == 1) {
            Node* temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            return head;
        }

        Node* curr = head;
        int count = 1;

        while (curr != NULL && count < x) {
            curr = curr->next;
            count++;
        }

        if (curr == NULL) return head;

        if (curr->prev != NULL)
            curr->prev->next = curr->next;

        if (curr->next != NULL)
            curr->next->prev = curr->prev;

        delete curr;
        return head;
    }
};
