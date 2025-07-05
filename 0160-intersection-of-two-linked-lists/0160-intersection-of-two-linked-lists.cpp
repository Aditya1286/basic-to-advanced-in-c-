class Solution {
public:
    ListNode* collision(ListNode* list1, ListNode* list2, int d) {
        ListNode* temp = list1;
        for(int i = 0; i < d && temp != nullptr; i++) {
            temp = temp->next;
        }
        list1 = temp;

        while(list1 && list2) {
            if(list1 == list2) {
                return list1;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int n1 = 0, n2 = 0;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while(temp1) {
            n1++;
            temp1 = temp1->next;
        }

        while(temp2) {
            n2++;
            temp2 = temp2->next;
        }

        if(n1 < n2) {
            return collision(head1, head2, n2 - n1);
        } else {
            return collision(head2, head1, n1 - n2);
        }
    }
};
