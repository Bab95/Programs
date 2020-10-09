class Solution {
public:
    struct trienode{
        bool isEnd;
        vector<trienode*> children;
        trienode():isEnd(false){
            children.assign(26,NULL);
        }
    };
    void insert(trienode* root,string& word){
        trienode* pcrawl = root;
        for(int i=0;i<word.length();++i){
            int index = word[i]-'a';
            if(pcrawl->children[index]==NULL){
                pcrawl->children[index] = new trienode();
            }
            pcrawl = pcrawl->children[index];
        }
        pcrawl->isEnd = true;
    }
    bool search(trienode* root,string& word){
        trienode* pcrawl = root;
        for(int i=0;i<word.length();++i){
            int index = word[i]-'a';
            if(pcrawl->children[index]==NULL||pcrawl->children[index]->isEnd==false){
                return false;
            }
            pcrawl = pcrawl->children[index];
        }
        return pcrawl!=NULL&&pcrawl->isEnd;
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        trienode* root = new trienode();
        for(auto s :words){
            insert(root,s);
        }
        string ans="";
        for(auto s:words){
            if(search(root,s)){
                if(ans.length()<s.length()){
                    ans = s;
                }else{
                    ans = min(ans,s);
                }
            }
        }
        return ans;
    }
};
