#define MAX 1000000
#define HASHKEY 1000
struct node{
        int key,value;
        node(int k,int v):key(k),value(v){}
};
vector<vector<node> > hashmap((MAX/HASHKEY )+1,vector<node>());
class MyHashMap {
public:
    /** Initialize your data structure here. */
    //int HASHKEY;
    MyHashMap() {
        //HASHKEY = 10;
        for(int i=0;i<hashmap.size();++i){
            hashmap[i].clear();
        }
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashkey = key/HASHKEY;
        node nnode(key,value);
        //nnode.key = key;
        //nnode.value = value;
        if(hashmap[hashkey].size()==0){
            hashmap[hashkey].push_back(nnode);
        }else{
            for(auto it=hashmap[hashkey].begin();it!=hashmap[hashkey].end();++it){
                if(it->key==key){
                    it->value = value;
                    return;
                }
            }
            hashmap[hashkey].push_back(nnode);
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashkey = key/HASHKEY;
        if(hashmap[hashkey].size()==0){
            return -1;
        }
        for(auto it=hashmap[hashkey].begin();it!=hashmap[hashkey].end();++it){
            if(it->key==key){
                return it->value;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashkey = key/HASHKEY;
        if(hashmap[hashkey].size()==0){
            return;
        }
        for(auto it=hashmap[hashkey].begin();it!=hashmap[hashkey].end();++it){
            if(it->key==key){
                hashmap[hashkey].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
