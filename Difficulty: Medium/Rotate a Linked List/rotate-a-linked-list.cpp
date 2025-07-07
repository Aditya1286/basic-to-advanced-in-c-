class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || !head->next || k == 0) return head;

        Node* temp = head;
        int size = 1;

        while (temp->next) {
            temp = temp->next;
            size++;
        }

        k = k % size;
        if (k == 0) return head;

        temp->next = head;

        int stepsToNewHead = k;
        temp = head;

        for (int i = 1; i < stepsToNewHead; i++) {
            temp = temp->next;
        }

        Node* newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};
