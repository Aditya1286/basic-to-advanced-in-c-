class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* nodi = new Node(x);
        
        if (head == NULL) {
            return nodi;
        }
        
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = nodi;
        return head;
    }
};
