class LRUCache {
    public:
    
        class ListNode{
        public: 
            int key, value;
            ListNode *prev, *next;
    
            ListNode(int key , int value){
                this->key = key;
                this->value = value;
                this->prev = nullptr;
                this->next = nullptr;
            }
        };
    
        ListNode *head = new ListNode(-1 , -1);
        ListNode *tail = new ListNode(-1 , -1);
    
        unordered_map <int , ListNode*> m;
        int limit;
    
        void addNode(ListNode *newNode){
            ListNode *oldNext = head->next;
    
            head->next = newNode;
            newNode->next = oldNext;
    
            oldNext->prev = newNode;
            newNode->prev = head;
        }
    
        void deleteNode(ListNode *oldNode){
            ListNode *oldPrev = oldNode->prev;
            ListNode *oldNext = oldNode->next;
    
            oldPrev->next = oldNext;
            oldNext->prev = oldPrev;
        }
    
        LRUCache(int capacity) {
            limit = capacity;
            head->next = tail;
            tail->prev = head;
        }
    
        int get(int key) {
            if(m.find(key) == m.end()){
                return -1;
            }
            ListNode *newUpdated = m[key];
            int ans = newUpdated->value;
            m.erase(key);
            deleteNode(newUpdated);
    
            addNode(newUpdated);
            m[key] = newUpdated;
    
            return ans;
        }
    
        void put(int key, int value) {
            if(m.find(key) != m.end()){
                ListNode *oldNode = m[key];
                m.erase(key);
                deleteNode(oldNode);
            }
            if(m.size() == limit){
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            ListNode *newNode = new ListNode(key , value);
            addNode(newNode);
            m[key] = newNode;
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */