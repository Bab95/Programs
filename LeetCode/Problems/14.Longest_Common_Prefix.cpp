class Solution {
public:
    struct node{
        bool isEnd;
        int count;
        struct node* children[26];
    };
    struct node* getnode(){
        struct node* tmp = new node;
        tmp->isEnd = false;
        tmp->count = 0;
        for(int i=0;i<26;i++){
            tmp->children[i] = NULL;
        }
        return tmp;
    }
    void insertTrie(struct node* root,string &s){
        struct node* pcrawl = root;
        for(int i=0;i<s.length();i++){
            int index = (int)s[i]-97;
            if(pcrawl->children[index]==NULL){
                pcrawl->children[index] = getnode();
            }
            pcrawl->children[index]->count+=1;
            pcrawl = pcrawl->children[index];
        }
        pcrawl->isEnd = true;
        cout<<"insertion Complete:"<<s<<endl;
    }
    int countChild(int *index,struct node* pcrawl){
        int res = 0;
        for(int i=0;i<26;i++){
            if(pcrawl->children[i]!=NULL){
                res++;
                *index = i;
            }
        }
        return res;
    }
    void printTrie(struct node *root){
        for(int i=0;i<26;i++){
            cout<<"level: "<<i+1<<" ";
            if(root->children[i]!=NULL){
                char c = (char)(i+97);
                cout<<c<<" ";
                root = root->children[i];
            }
            cout<<endl;
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        struct node* root = getnode();
        for(int i=0;i<strs.size();i++){
            insertTrie(root,strs[i]);
        }
        printTrie(root);
        struct node* pcrawl = root;
        string res;
        int index = -1;
        while(pcrawl!=NULL&&pcrawl->isEnd!=true){
            int child = countChild(&index,pcrawl);
            if(child>1){
                break;
            }else if(child==1){
                char c = (char)(index+97);
                res.push_back(c);
            }else{
                break;
            }
            pcrawl = pcrawl->children[index];
        }
        return res;
    }
};
