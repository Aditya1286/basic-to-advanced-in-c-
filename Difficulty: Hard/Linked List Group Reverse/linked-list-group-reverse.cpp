class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;

        Node* temp = head;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        count = 0;
        while (current != nullptr && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};
