class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current != nullptr) {
            bool isDuplicate = false;
            
            while (current->next != nullptr && current->val == current->next->val) {
                current = current->next;
                isDuplicate = true;
            }
            
            if (isDuplicate) {
                prev->next = current->next;
            } else {
                prev = prev->next;
            }
            
            current = current->next;
        }
        
        return dummy->next;
    }
};