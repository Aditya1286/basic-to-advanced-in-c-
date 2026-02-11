class LRUCache {    
public:
    class Node{
        public:
        int key,value;
        Node* prev;
        Node* next;
        Node(int k,int v){
            this->key=k;
            this->value=v;
            prev=next=nullptr;
        }
    };
    int capacity;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;

    LRUCache(int cap) {
        capacity=cap;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Node* node){
        Node* prevnode=node->prev;
        Node* nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }
    void insertAfterHead(Node* node){
        Node* nextnode=head->next;
        head->next=node;
        node->prev=head;
        node->next=nextnode;
        nextnode->prev=node;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        Node* node = mp[key];
        int value=node->value;
        deleteNode(node);
        insertAfterHead(node);
        return value;

    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
        }
        if(mp.size()==capacity){
            Node* lru=tail->prev;
            int key = lru->key;
            deleteNode(lru);
            mp.erase(key);
        }
        Node* newnode = new Node(key,value);
        insertAfterHead(newnode);
        mp[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */