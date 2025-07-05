

class Solution {
  public:
    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        Node* mid = getMiddle(head);
        Node* right = mid->next;
        mid->next = NULL;

        Node* leftSorted = mergeSort(head);
        Node* rightSorted = mergeSort(right);

        return merge(leftSorted, rightSorted);
    }

  private:
    Node* getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* merge(Node* l1, Node* l2) {
        Node dummy(0);
        Node* tail = &dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->data < l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1 != NULL) tail->next = l1;
        if (l2 != NULL) tail->next = l2;

        return dummy.next;
    }
};
