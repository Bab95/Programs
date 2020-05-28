class LRUCache {
public:
    struct ListNode{
        int key,value;
        struct ListNode *prev,*next;
        ListNode(int k,int v):key(k),value(v),prev(NULL),next(NULL){}
    };
    unordered_map<int,ListNode*> mmap;
    int current = 0;
    int total_cap = -1;
    ListNode* head,*tail;
    LRUCache(int capacity) {
        current  = 0;
        total_cap = capacity;
        head = NULL;
        tail = NULL;
    }
    void printList(ListNode* headnode){
        while(headnode!=NULL){
            cout<<headnode->key<<" "<<headnode->value<<endl;
            headnode = headnode->next;
        }
        return;
    }
    void insert_at_begin(ListNode** head_ref,int k,int v,ListNode** tail_ref){
        ListNode* head_node = *head_ref;
        if(head_node==NULL){
            head_node = new ListNode(k,v);
            *head_ref = head_node;
            *tail_ref = *head_ref;
            return;
        }
        ListNode* newnode = new ListNode(k,v);
        newnode->next = head_node;
        head_node->prev = newnode;
        head_node = newnode;
        *head_ref = head_node;
        return;
    }
    void insert_node_at_begin(ListNode** head_ref,ListNode* node){
        ListNode* head_node = *head_ref;
        node->next = head_node;
        head_node->prev = node;
        head_node = node;
        *head_ref = head_node;
        return;
    }
    ListNode* delete_at_end(ListNode** head_ref,ListNode** tail_ref){
        ListNode* head_node = *head_ref;

        //only one node....
        if(head_node->next==NULL){
            *head_ref = NULL;
            return head_node;
        }

        ListNode* tail_node = *tail_ref;
        tail_node->prev->next = NULL;
        *tail_ref = tail_node->prev;
        tail_node->prev = NULL;
        return tail_node;
    }
    ListNode* delete_node(ListNode** head_ref,ListNode* node){
        node->prev->next = node->next;
        if(node->next!=NULL){
            node->next->prev = node->prev;
            node->next = NULL;
        }
        node->prev = NULL;
        return node;
    }
    int get(int key) {

        /*cout<<"get function"<<endl;
        printList(head);*/

        if(mmap.find(key)==mmap.end()){
            return -1;
        }
        int ans = mmap[key]->value;
        ListNode* node = mmap[key];
        if(node==head){
            //already at front....
            return ans;
        }else if(node==tail){
            ListNode* nnode = delete_at_end(&head,&tail);
            insert_node_at_begin(&head,nnode);
        }else{
            ListNode* nnode = delete_node(&head,mmap[key]);
            insert_node_at_begin(&head,nnode);
        }
        return ans;
    }

    void put(int key, int value) {

        if(mmap.find(key)==mmap.end()){
            insert_at_begin(&head,key,value,&tail);
            mmap[key] = head;
            current++;
            if(current>total_cap){
                ListNode* nnode = delete_at_end(&head,&tail);
                mmap.erase(nnode->key);
                current--;
                delete nnode;
            }
        }else{
            //key already present need to bring front.....
            ListNode* node = mmap[key];
            node->value = value;
            if(node==head){
                //already at front....
                return;
            }else if(node==tail){
                ListNode* nnode = delete_at_end(&head,&tail);
                insert_node_at_begin(&head,nnode);
            }else{
                ListNode* nnode = delete_node(&head,mmap[key]);
                insert_node_at_begin(&head,nnode);
            }
        }

        /*cout<<"put function"<<endl;
        printList(head);*/

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
