class Solution {
public:
    struct trieNode{
        struct trieNode* child[26];
        bool isEnd;
        trieNode() : isEnd(false){
            for (int i=0;i<26;i++){
                child[i] = NULL;
            }
        }
    };
    trieNode* root = new trieNode();

    void insert(string word) {
        trieNode* p = root;
        for (int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if (!p->child[c]){
                p->child[c] = new trieNode();
            }
            p = p->child[c];
        }
        p->isEnd = true;
    }
    string search_root(string word) {
        /*if (root->child[word[0]-'a'] == NULL){
            return "";
        }*/
        trieNode* p = root;
        int i = 0;
        string root_word;
        while (p && p->isEnd == false && i < word.length()){
            int c = word[i] - 'a';
            root_word.push_back(word[i]);
            if (p->child[c]){
                p = p->child[c];
            }else{
                return "";
            }
            i++;
        }
        if (p && p->isEnd) {
            //cout << word <<" " << root_word << endl;
            return root_word;
        }
        return "";
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (int i=0;i<dictionary.size();i++){
            insert(dictionary[i]);
        }
        stringstream ss(sentence);
        string str;
        string result;
        while (ss >> str){
            string replacement = search_root(str);
            if (replacement == ""){
                result += str;
            }else {
                result += replacement;
            }
            result += " ";
        }
        if (result.back() == ' '){
            result.pop_back();
        }
        return result;
    }
};
