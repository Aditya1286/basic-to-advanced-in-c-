class Solution {
public:
    ListNode* findknode(ListNode* head, int k){
        k -= 1;
        while(head != nullptr && k > 0){
            k--;
            head = head->next;
        }
        return head;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* nodi = head->next;
            head->next = prev;
            prev = head;
            head = nodi;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* kthnode = findknode(temp, k);
            if(kthnode == nullptr){
                if(prev) prev->next = temp; 
                break;
            }

            nextNode = kthnode->next;
            kthnode->next = nullptr;

           ListNode* reversedHead = reverse(temp); 

            if(temp == head){
                head = reversedHead;
            } else {
                prev->next = reversedHead;
            }

            prev = temp;
            temp = nextNode; 
        }

        return head;
    }
};
