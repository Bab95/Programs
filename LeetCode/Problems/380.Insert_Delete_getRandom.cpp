class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> mmap;
    int n;
    vector<int> values;
    RandomizedSet() {
        n = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mmap.count(val)!=0){
            return false;
        }
        values.push_back(val);
        mmap[val] = n;
        ++n;
        return true;
     }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(n<=0){
            return false;
        }
        if(mmap.count(val)==0){
            return false;
        }
        int val_index = mmap[val];
        mmap[values[n-1]] = mmap[val];
        swap(values[val_index],values[n-1]);
        n--;
        mmap.erase(val);
        values.pop_back();
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int random_index = rand()%n;
        return values[random_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */