class Solution {
private:
    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (left && right) {

            if (left->val <= right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }

            current = current->next;
        }

        current->next = left ? left : right;

        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* current = nullptr;

        for (auto list : lists) {
            current = merge(current, list);
        }

        return current;
    }
};