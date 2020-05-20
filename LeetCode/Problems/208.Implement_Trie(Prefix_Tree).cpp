class Trie {
public:
    /** Initialize your data structure here. */
    struct trienode{
        bool is_end;
        trienode* children[26];
        trienode(){
            is_end = false;
            for(int i=0;i<26;++i){
                children[i] = NULL;
            }
        }
    };
    trienode* root;
    Trie() {
        root = new trienode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        trienode* p = root;
        for(int i=0;i<word.length();++i){
            if(p->children[word[i]-'a']==NULL){
                p->children[word[i]-'a'] = new trienode();
            }
            p = p->children[word[i]-'a'];
        }
        p->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        trienode* p = root;
        for(int i=0;i<word.length();++i){
            if(p->children[word[i]-'a']==NULL){
                return false;
            }else{
                p = p->children[word[i]-'a'];
            }
        }
        if(p&&p->is_end){
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        trienode* p = root;
        for(int i=0;i<word.length();++i){
            if(p->children[word[i]-'a']==NULL){
                return false;
            }else{
                p = p->children[word[i]-'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
