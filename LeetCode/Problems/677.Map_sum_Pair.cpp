class MapSum {
public:
    /** Initialize your data structure here. */
    struct trienode{
        int _sum;
        struct trienode* child[26];
        trienode():_sum(0){
            for(int i=0;i<26;++i){
                child[i] = NULL;
            }
        }
    };
    unordered_set<string> ss;
    trienode* root;
    MapSum() {
        root = new trienode();
    }

    void insert(string key, int val) {
        if(ss.count(key)==0){
            //new key so addition..
            struct trienode* pcrawl = root;
            for(int i=0;i<key.length();++i){
                int index = key[i]-'a';
                if(pcrawl->child[index]==NULL){
                    pcrawl->child[index] = new trienode();
                }
                pcrawl->child[index]->_sum+=val;
                pcrawl = pcrawl->child[index];
            }
            ss.insert(key);
        }else{
            struct trienode* pcrawl = root;
            for(int i=0;i<key.length();++i){
                int index = key[i]-'a';
                if(pcrawl->child[index]==NULL){
                    pcrawl->child[index] = new trienode();
                }
                pcrawl->child[index]->_sum = val;
                pcrawl = pcrawl->child[index];
            }
        }
    }

    int sum(string prefix) {
        struct trienode* pcrawl = root;
        int ans = 0;
        for(int i=0;i<prefix.length();++i){
            if(!pcrawl->child[prefix[i]-'a']){
                return 0;
            }
            ans = pcrawl->child[prefix[i]-'a']->_sum;
            pcrawl = pcrawl->child[prefix[i]-'a'];
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

/*
["MapSum", "insert", "sum", "insert", "sum","insert","sum"]
[[], ["apple",3], ["ap"], ["app",2], ["ap"],["appl",4],["applepenpineapple"]]
*/
