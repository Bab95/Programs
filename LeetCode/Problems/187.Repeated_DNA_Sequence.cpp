class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10){
            return {};
        }
        unordered_map<string,int> mmap;
        for(int i=0;i<=s.length()-10;++i){
            string a = s.substr(i,10);
            mmap[a] += 1;
        }
        vector<string> ans;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if(it->second>1){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
