class Solution {
  public:
    int getLength(Node* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    Node* getIntersection(Node* head1, Node* head2, int diff) {
       while (diff--) {
            head1 = head1->next;
        }

       while (head1 && head2) {
            if (head1 == head2) {
                return head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return nullptr;
    }

    Node* intersectPoint(Node* head1, Node* head2) {
        int len1 = getLength(head1);
        int len2 = getLength(head2);

        if (len1 > len2) {
            return getIntersection(head1, head2, len1 - len2);
        } else {
            return getIntersection(head2, head1, len2 - len1);
        }
    }
};
