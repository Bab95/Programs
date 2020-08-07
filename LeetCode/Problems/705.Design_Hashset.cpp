const long int max_size = 1000000;
class MyHashSet {
public:
    /** Initialize your data structure here. */

    bitset<max_size> hash_set;
    MyHashSet() {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
    }

    void add(int key) {
        hash_set.set(key);
    }

    void remove(int key) {
        hash_set.reset(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash_set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
