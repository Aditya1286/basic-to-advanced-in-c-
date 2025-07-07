class Solution {
  public:
    Node* reverse(Node* head){
        Node* current = NULL;
        Node* temp = head;
        while(temp){
            Node* nextNode = temp->next;
            temp->next = current;
            current = temp;
            temp = nextNode;
        }
        return current;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
       num1 = reverse(num1);
        num2 = reverse(num2);

        Node* dummy = new Node(-1);
        Node* curr = dummy;
        int carry = 0;

        while(num1 != NULL || num2 != NULL || carry){
            int sum = carry;
            if(num1){
                sum += num1->data;
                num1 = num1->next;
            }
            if(num2){
                sum += num2->data;
                num2 = num2->next;
            }

            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }

        Node* result = reverse(dummy->next);

        while(result && result->data == 0 && result->next != NULL){
            result = result->next;
        }

        return result;
    }
};
