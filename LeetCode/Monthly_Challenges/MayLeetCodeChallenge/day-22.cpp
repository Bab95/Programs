class Solution {
public:
    static bool compare(const pair<int,char>& p1,const pair<int,char>& p2){
        if(p1.first>p2.first){
            return true;
        }
        return false;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mmap;
        for(int i=0;i<s.length();++i){
            mmap[s[i]]+=1;
        }
        string ans;
        ans.reserve(s.length());
        vector<pair<int,char> > freq;
        freq.reserve(mmap.size());
        for(auto it=mmap.begin();it!=mmap.end();++it){
            freq.push_back(make_pair(it->second,it->first));
        }
        sort(freq.begin(),freq.end(),compare);
        for(auto it=freq.begin();it!=freq.end();++it){
            for(int i=0;i<it->first;++i){
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};
