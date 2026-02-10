/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    void reorderList(Node* head) {
        if(head==nullptr || head->next==nullptr)return ;
        Node* fast = head;
        Node* slow = head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node* prev = NULL;
        Node* current = slow->next;
        slow->next=NULL;
        while(current){
            Node* nextnode = current->next;
            current->next=prev;
            prev = current;
            current = nextnode;
        }
        Node* first = head;
        Node* second = prev;
        while(second){
            Node* t1=first->next;
            Node* t2 = second->next;
            first->next=second;
            second->next=t1;
            first = t1;
            second = t2;
        }
    }
};