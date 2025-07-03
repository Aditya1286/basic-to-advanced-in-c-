class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(head == NULL) return head;

        if(x == 1){
            Node* temp = head;
            head = head->next;
            free(temp);
            return head;
        }

        int count = 1;
        Node* temp = head;
        Node* prev = NULL;

        while(temp != NULL && count < x){
            prev = temp;
            temp = temp->next;
            count++;
        }

        if(temp != NULL && prev != NULL){
            prev->next = temp->next;
            free(temp); 
        }

        return head;
    }
};
