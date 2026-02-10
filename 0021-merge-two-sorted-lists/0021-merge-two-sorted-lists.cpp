/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;
        while(curr1!=nullptr && curr2!=nullptr){
            if(curr1->val<=curr2->val){
                dummy->next=curr1;
                curr1=curr1->next;
                dummy = dummy->next;
            }
            else{
                dummy->next=curr2;
                curr2=curr2->next;
                dummy = dummy->next;
            }
        }
        if(curr1!=nullptr){
            dummy->next=curr1;
        }
        if(curr2!=nullptr){
            dummy->next=curr2;
        }
        return temp->next;
    }
};