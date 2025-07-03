class Solution {
  public:
    int GetNth(Node *head, int index) {
        Node* temp = head;
        int count = 1;
        
        while (temp != NULL) {
            if (count == index) {
                return temp->data;
            }
            count++;
            temp = temp->next;
        }
        
        return -1;
    }
};
