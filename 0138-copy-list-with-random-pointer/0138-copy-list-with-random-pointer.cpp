class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node* temp = head;
        while (temp) {
            Node* copynode = new Node(temp->val);
            copynode->next = temp->next;
            temp->next = copynode;
            temp = copynode->next;
        }
        
        temp = head;
        while (temp) {
            Node* copynode = temp->next;
            copynode->random = temp->random 
                               ? temp->random->next 
                               : nullptr;
            temp = copynode->next;
        }
        
        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while (temp) {
            Node* copynode = temp->next;
            temp->next = copynode->next;
            res->next = copynode;
            res = copynode;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};
