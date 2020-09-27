class FileSystem {
public:
    struct directory{
        string content;
        string name;
        bool file;
        map<string,directory*> children;
        directory(string _name){
            name = _name;
            content = "";
            file = false;
        }
    };
    struct directory* root = NULL;
    FileSystem() {
        root = new directory("/");
    }

    vector<string> ls(string path) {
        stack<directory*> stk;
        directory* pcrawl = root;
        string current;
        for(int i=1;i<path.length();++i){
            if(path[i]=='/'){
                stk.push(pcrawl);
                pcrawl = pcrawl->children[current];
                current.clear();
            }else{
                current.push_back(path[i]);
            }
        }
        //cout<<current<<endl;
        vector<string> ans;
        if(pcrawl==NULL){
            return {};
        }
        if(pcrawl->children.find(current)!=pcrawl->children.end()&&pcrawl->children[current]->file!=true){
            pcrawl = pcrawl->children[current];
        }else if(pcrawl->children.find(current)!=pcrawl->children.end()&&pcrawl->children[current]->file==true){
            return {current};
        }
        for(auto it=pcrawl->children.begin();it!=pcrawl->children.end();++it){
            ans.push_back(it->first);
        }
        return ans;
    }

    void mkdir(string path) {
        struct directory* pcrawl = root;
        string current;
        for(int i=1;i<path.length();++i){
            if(path[i]=='/'){
                if(pcrawl->children.find(current)==pcrawl->children.end()){
                    pcrawl->children.insert({current,new directory(current)});
                }
                pcrawl = pcrawl->children[current];
                current.clear();
            }else{
                current.push_back(path[i]);
            }
        }
        struct directory* ndirectory = new directory(current);
        pcrawl->children.insert({current,ndirectory});
    }

    void addContentToFile(string path, string content) {
        struct directory* pcrawl = root;
        string current;
        for(int i=1;i<path.length();++i){
            if(path[i]=='/'){
                pcrawl = pcrawl->children[current];
                current.clear();
            }else{
                current.push_back(path[i]);
            }
        }
        if(pcrawl->children.find(current)==pcrawl->children.end()){
            pcrawl->children.insert({current,new directory(current)});
        }
        pcrawl = pcrawl->children[current];
        pcrawl->file = true;
        //cout<<pcrawl->name<<endl;
        pcrawl->content = pcrawl->content.append(content);
    }

    string readContentFromFile(string path) {
        struct directory* pcrawl = root;
        string current;
        for(int i=1;i<path.length();++i){
            if(path[i]=='/'){
                pcrawl = pcrawl->children[current];
                current.clear();
            }else{
                current.push_back(path[i]);
            }
        }
        pcrawl = pcrawl->children[current];
        return pcrawl->content;
    }
};
/*

["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile","addContentToFile","readContentFromFile"]
[[],["/"],["/a/b/c"],["/a/b/c/d","hello world"],["/"],["/a/b/c/d"],["/a/b/c/d"," hello hello world"],["/a/b/c/d"]]
["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
["FileSystem","ls","mkdir","ls"]
[[],["/"],["/a/b/c"],["/a/b"]]
["FileSystem","mkdir","ls","ls","mkdir","ls","ls","addContentToFile","ls","ls","ls"]
[[],["/goowmfn"],["/goowmfn"],["/"],["/z"],["/"],["/"],["/goowmfn/c","shetopcy"],["/z"],["/goowmfn"],["/goowmfn"]]
["FileSystem","mkdir","ls","ls","mkdir","ls","ls","addContentToFile","ls","ls","ls"]
[[],["/goowmfn"],["/goowmfn"],["/"],["/z"],["/"],["/"],["/goowmfn/c","shetopcy"],["/z"],["/goowmfn/c"],["/goowmfn"]]
*/
/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
