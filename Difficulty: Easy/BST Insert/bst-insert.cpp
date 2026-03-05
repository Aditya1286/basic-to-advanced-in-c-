/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* insert(Node* root, int key) {
       Node* node =new Node(key);
       if(root==NULL)return node;
       Node* curr = root;
       while(true){
           if(key<curr->data){
               if(curr->left==NULL){
                   curr->left=node;
                   break;
               }
               curr=curr->left;
           }
           else{
               if(curr->right==NULL){
                   curr->right=node;
                   break;
               }
               curr=curr->right;
           }
       }
       return root;
    }
};