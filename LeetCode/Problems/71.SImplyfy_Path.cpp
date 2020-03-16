class Solution {
public:
    vector<string> split(string path){
        vector<string> directories;
        directories.push_back("root");
        //vector<char> directory;
        string directory;
        for(int i=1;i<path.length();i++){
            if(path[i]=='/'){
                if(directory.length()!=0&&directory!="."){
                    directories.push_back(directory);
                    directory.erase();
                }
                continue;
            }
            directory.push_back(path[i]);
        }
        return directories;
    }
    string simplifyPath(string path) {
        vector<string> directories = split(path);
        for(string &s: directories){
            cout<<s<<endl;
        }
        stack<string> stk;
        stk.push(directories[0]);
        for(int i=1;i<directories.size();i++){
            if(directories[i].compare("..")==0){
                if(stk.size()>1){
                    stk.pop();
                }
                /*else if(stk.size()==1){
                    return "/";
                }*/
            }else{
                stk.push(directories[i]);
            }
        }
        string result = "/";
        cout<<stk.size()<<endl;
        while(!stk.empty()){
            string tmp = stk.top();
            stk.pop();
            /*if(tmp=="root"){
                if(result.size()!=0&&result[0]!='/'){
                    result = "/" + result;
                }
                break;
            }*/
            if(tmp=="root"){
                break;
            }
            //tmp = tmp;
            result = tmp.append(result);
        }

        return result;
    }
};
