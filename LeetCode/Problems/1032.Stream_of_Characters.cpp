class StreamChecker {
public:
    struct trienode{
        struct trienode* child[26];
        bool is_end;
        trienode():is_end(false){
            for(int i=0;i<26;++i){
                child[i] = NULL;
            }
        }
    };
    string current;
    trienode *root = NULL;
    void insert(trienode* root,string& s){
        trienode* pcrawl = root;
        for(int i=s.length()-1;i>=0;i--){
            int index = s[i]-'a';
            if(pcrawl->child[index]==NULL){
                pcrawl->child[index] = new trienode();
            }
            pcrawl = pcrawl->child[index];
        }
        pcrawl->is_end = true;
    }
    bool search(trienode* root,string& str){
        trienode* pcrawl = root;
        for(int i=str.length()-1;i>=0;i--){
            int index = str[i] - 'a';
            if(pcrawl->is_end){
                return true;
            }
            if(pcrawl->child[index]==NULL){
                return false;
            }

            pcrawl = pcrawl->child[index];
        }
        return pcrawl!=NULL&&pcrawl->is_end;
    }
    StreamChecker(vector<string>& words) {
        root = new trienode();
        for(int i=0;i<words.size();++i){
            insert(root,words[i]);
        }
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    bool query(char letter) {
        current.push_back(letter);
        return search(root,current);
    }
};
/*
["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query","query","query"]
[[["cd","f","kl"]],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],["k"],["l"],["c"],["d"]]
["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query"]
[[["ab","ba","aaab","abab","baa"]],["a"],["a"],["a"],["a"],["a"],["b"],["a"],["b"],["a"],["b"],["b"],["b"],["a"],["b"],["a"],["b"],["b"],["b"],["b"],["a"],["b"],["a"],["b"],["a"],["a"],["a"],["b"],["a"],["a"],["a"]]
["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query"]
[[["abaa","abaab","aabbb","bab","ab"]],["a"],["a"],["b"],["b"],["b"],["a"],["a"],["b"],["b"],["a"],["a"],["a"],["a"],["b"],["a"],["b"],["b"],["b"],["a"],["b"],["b"],["b"],["a"],["a"],["a"],["a"],["a"],["b"],["a"],["b"],["b"],["b"],["a"],["a"],["b"],["b"],["b"],["a"],["b"],["a"]]
["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query","query","query"]
[[["cd","f","kl"]],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],["k"],["l"],["c"],["d"]]
["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query","query"]
[[["ab","ba","aaab","abab","baa"]],["a"],["a"],["a"],["a"],["a"],["b"],["a"],["b"],["a"],["b"],["b"],["b"],["a"],["b"],["a"],["b"],["b"],["b"],["b"],["a"],["b"],["a"],["b"],["a"],["a"],["a"],["b"],["a"],["a"],["a"]]
*/
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
