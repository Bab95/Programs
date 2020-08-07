class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct trienode{
        struct trienode* child[26];
        bool is_end;
        trienode():is_end(false){
            for(int i=0;i<26;++i){
                child[i] = NULL;
            }
        }
    };
    trienode* root = NULL;
    WordDictionary() {
        root = new trienode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        struct trienode* pcrawl = root;
        for(int i=0;i<word.length();++i){
            if(pcrawl->child[word[i]-'a']==NULL){
                pcrawl->child[word[i]-'a'] = new trienode();
            }
            pcrawl = pcrawl->child[word[i]-'a'];
        }
        pcrawl->is_end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool _search(trienode* _root,string& word,int index){
        if(!_root){
            return false;
        }
        if(index==word.length()){
            if(_root!=NULL&&_root->is_end){
                return true;
            }
            return false;
        }
        if(word[index]=='.'){
            bool ans = true;
            for(char c='a';c<='z';c++){
                if(_root->child[c-'a']!=NULL){
                    ans = _search(_root->child[c-'a'],word,index+1);
                    if(ans==true){
                        return ans;
                    }
                }
            }

        }
        else {
            return _search(_root->child[word[index]-'a'],word,index+1);
        }
        return false;
    }
    bool search(string word) {
        struct trienode* pcrawl = root;
        return _search(pcrawl,word,0);

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/*
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]

["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
[[],["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]


["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
[[],["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]

*/
