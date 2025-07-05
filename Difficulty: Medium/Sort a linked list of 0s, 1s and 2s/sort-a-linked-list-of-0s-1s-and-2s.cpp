class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zeroDummy = new Node(-1);
        Node* oneDummy = new Node(-1);
        Node* twoDummy = new Node(-1);

        Node* zero = zeroDummy;
        Node* one = oneDummy;
        Node* two = twoDummy;

        Node* temp = head;

        while (temp) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            } else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            } else if (temp->data == 2) {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        zero->next = oneDummy->next ? oneDummy->next : twoDummy->next;
        one->next = twoDummy->next;
        two->next = NULL;

        Node* newHead = zeroDummy->next;

        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;

        return newHead;
    }
};
