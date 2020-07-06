class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> set;
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(set.count(val)==0){
            set.insert(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(set.count(val)==0){
            return false;
        }
        set.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int size = set.size();
        int n = rand()%size;
        auto itr = set.begin();
        advance(itr,n);
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
