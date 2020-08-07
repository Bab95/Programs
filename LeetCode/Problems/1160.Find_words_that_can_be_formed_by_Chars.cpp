class Solution {
public:
    unordered_map<char,int> mmap;
    bool contains(string& s){
        unordered_map<char,int> s_map;
        for(auto &c : s){
            s_map[c] += 1;
        }
        for(auto it=s_map.begin();it!=s_map.end();++it){
            if(mmap.find(it->first)==mmap.end()){
                return false;
            }else if(mmap[it->first]<it->second){
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        for(auto &c : chars){
            mmap[c] += 1;
        }
        for(auto it : words){
            if(contains(it)){
                cout<<it<<endl;
                ans += it.length();
            }
        }
        return ans;
    }
};
