class Solution {
public:
    struct trienode{
        bool is_end;
        vector<trienode*> child;
        vector<string> suggestions;
        trienode():is_end(false){
            for(int i=0;i<26;++i){
                child.push_back(NULL);
            }
        }
    };
    void insert_trie(trienode* root,string& str){
        struct trienode* pcrawl = root;
        for(int i=0;i<str.length();++i){
            int index = str[i]-'a';
            if(pcrawl->child[index]==NULL){
                pcrawl->child[index] = new trienode();
            }
            pcrawl = pcrawl->child[index];
            if(pcrawl->suggestions.size()<3){
                pcrawl->suggestions.push_back(str);
            }
        }
        pcrawl->is_end = true;
    }
    void print(vector<string>& s){
        for(auto it : s){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    void getWord(trienode* root,string& s,vector<vector<string> >& ans){
        struct trienode* pcrawl = root;
        for(int i=0;i<s.length();++i){
            int index = s[i]-'a';
            //cout<<s[i]<<" : ";
            if(pcrawl->child[index]!=NULL){
                pcrawl = pcrawl->child[index];
                //print(pcrawl->suggestions);
                ans.push_back(pcrawl->suggestions);
            }else{
                break;
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        struct trienode* root = new trienode();
        for(int i=0;i<products.size();++i){
            insert_trie(root,products[i]);
        }
        vector<vector<string> > ans;
        getWord(root,searchWord,ans);
        if(ans.size()!=searchWord.length()){
            while(ans.size()<searchWord.length())
                ans.push_back({});
        }
        return ans;
    }
};
