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
    ListNode* middlee(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val < list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1)temp->next=list1;
        else temp->next=list2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
     if(head==nullptr || head->next==nullptr)return head;
     ListNode* middle=middlee(head);
     ListNode* lefthead=head;
     ListNode* righthead=middle->next;
     middle->next=nullptr;
     lefthead=sortList(lefthead);
     righthead=sortList(righthead);
     return merge(lefthead,righthead);
    }
};