class Solution {
  public:
    Node *addNode(Node *head, int pos, int data) {
        Node* temp = head;
        int count = 0;

        while (count < pos && temp != NULL) {
            temp = temp->next;
            count++;
        }

        Node* newNode = new Node(data);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;

        return head;
    }
};
