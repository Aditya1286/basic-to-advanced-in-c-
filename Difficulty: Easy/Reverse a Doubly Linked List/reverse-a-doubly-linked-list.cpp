class Solution {
  public:
    DLLNode* reverseDLL(DLLNode* head) {
        DLLNode* current = head;
        DLLNode* temp = NULL;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != NULL)
            head = temp->prev;

        return head;
    }
};
