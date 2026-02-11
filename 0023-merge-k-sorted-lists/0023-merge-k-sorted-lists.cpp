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
private:
    ListNode* mergetwoList(ListNode* l1,ListNode* l2){
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        if(l1->val<=l2->val){
            l1->next=mergetwoList(l1->next,l2);
            return l1;
        } 
        else{
            l2->next=mergetwoList(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partition(int start, int end, vector<ListNode*>& lists){
        if(start>end)return NULL;
        if(start==end)return lists[start];
        int mid=start+(end-start)/2;
        ListNode* l1=partition(start,mid,lists);
        ListNode* l2=partition(mid+1,end,lists);
        return mergetwoList(l1,l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0)return NULL;
        return partition(0,k-1,lists);
    }
};