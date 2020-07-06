class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> visited;
        vector<string> ans;
        ans.reserve(names.size());
        for(int i=0;i<names.size();++i){
            if(visited.find(names[i])==visited.end()){
                visited[names[i]] = 1;
            }else{
                int counter = visited[names[i]];
                string tmp = names[i];
                tmp.push_back('(');
                tmp = tmp.append(to_string(counter));
                tmp.push_back(')');
                while(visited.find(tmp)!=visited.end()){
                    while(tmp[tmp.length()-1]!='('){
                        tmp.pop_back();
                    }
                    counter++;
                    tmp = tmp.append(to_string(counter));
                    tmp.push_back(')');
                }
                visited[names[i]] = counter;
                visited[tmp] = true;
                names[i] = tmp;
            }
        }
        return names;
    }
};
