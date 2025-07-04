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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* nodi=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nodi;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* headd=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=headd;
        while(second){
            if(first->val!=second->val){
                reverse(headd);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(headd);
        return true;
    }
};