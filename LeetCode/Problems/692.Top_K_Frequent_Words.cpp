unordered_map<string,int> mmap;
bool compare(const string& s1,const string& s2){
    if(mmap[s1]>mmap[s2]){
        return true;
    }
    if(mmap[s1]==mmap[s2]){
        if(s1.compare(s2)<0){
            return true;
        }
    }
    return false;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        mmap.clear();
        for(int i=0;i<words.size();++i){
            mmap[words[i]]++;
        }
        vector<string> ans;
        ans.reserve(mmap.size());
        for(auto it=mmap.begin();it!=mmap.end();++it){
            ans.push_back(it->first);
        }
        sort(ans.begin(),ans.end(),compare);
        ans.erase(ans.begin()+k,ans.end());
        return ans;
    }
};
    
