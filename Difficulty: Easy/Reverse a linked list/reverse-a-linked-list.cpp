/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* prev=NULL;
        Node* temp=head;
        while(temp){
            Node* nodi=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nodi;
        }
        return prev;
    }
};