class Node{
    public: 
    int key,value;
    Node* prev,*next;

    Node(int k, int v){
        key = k;
        value = v;
        prev = next = NULL;
    }
}
class LRUCache {
public:
    Node* head = newNode(-1,-1);
    Node* tail = newNode(-1,-1);
    // we are creating the map bcz through map we can retrieve the values quickly
    unordered_map<int,Node*>m;
    int limit;

    void addNode(Node* newnode){
        Node* headnext = head->next;
        head->next = newnode;
        tail->prev = newnode;
        newnode->prev = head;
        newnode->next = headnext;
    }
    void deleteNode(Node* oldnode){
        Node* oldPrev = oldnode->prev;
        Node* oldNext = oldnode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m[key] == m.end()) return -1;
        int ans = m[key]->val;
    }
    
    void put(int key, int value) {
        if(m[key] != m.end()){
            Node* oldNode = m[key];
            m.erase(key);
            deleteNode(oldNode);
        }
        if(m.size() == limit){
            // remove the least recently used node
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key,value);
        addNode(newNode); //updating the doubly linked list
        m[key] = val; //updating the map

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */