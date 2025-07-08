class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* curr = *head_ref;

        while (curr != NULL) {
            Node* next = curr->next;

            if (curr->data == x) {
                // If current node is head
                if (curr == *head_ref) {
                    *head_ref = curr->next;
                    if (*head_ref != NULL)
                        (*head_ref)->prev = NULL;
                } else {
                    if (curr->prev)
                        curr->prev->next = curr->next;
                    if (curr->next)
                        curr->next->prev = curr->prev;
                }

                delete curr;
            }

            curr = next;
        }
    }
};
