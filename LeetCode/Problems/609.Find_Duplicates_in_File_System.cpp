class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string> > ans;
        unordered_map<string,vector<string> > mmap;
        //file content to file path map

        for(int i=0;i<paths.size();++i){
            istringstream ss(paths[i]);
            string rpath;
            ss>>rpath;
            while(ss){
                string file;
                ss>>file;
                size_t found = file.find("(");
                if(found!=string::npos){
                    string file_name = file.substr(0,found);
                    string content = file.substr(found+1,file.size()-found-2);
                    mmap[content].push_back(rpath+"/"+file_name);
                }
            }
        }
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if(it->second.size()>1){
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};
