class LRUCache {
    int cap;
    class node{
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int k,int v){
            key=k;
            val=v;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    unordered_map<int,node*> mp;
public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(node *n){
        node *temp=n->next;
        n->prev->next=temp;
        temp->prev=n->prev; 
    }   
    void addNode(node *n){
        node *t=head->next;
        head->next=n;
        n->prev=head;
        n->next=t;
        t->prev=n;
    } 
    int get(int k) {
        if(mp.find(k)!=mp.end()){
            node *t=mp[k];
            int res=t->val;
            mp.erase(k);
            deleteNode(t);
            addNode(t);
            mp[k]=head->next;
            return res;
        }
        return -1;
    }    
    void put(int k, int v) {
        if(mp.find(k)!=mp.end()){
            node *t=mp[k];
            mp.erase(k);
            deleteNode(t);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node* n=new node(k,v);
        addNode(n);
        mp[k]=n;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */