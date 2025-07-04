/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int length(Node* slow,Node* fast){
        int count=1;
        fast=fast->next;
        while(slow!=fast){
            count++;
            fast=fast->next;
        }
        return count;
    }
    int countNodesinLoop(Node *head) {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return length(slow,fast);
            }
        }
        return 0;
    }
};