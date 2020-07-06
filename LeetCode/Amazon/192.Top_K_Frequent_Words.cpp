class Solution {
public:
    static bool mycompare(const pair<int,string>& a,const pair<int,string>& b){
        if(a.first>b.first){
            return true;
        }
        if(a.first==b.first){
            if(a.second<b.second){
                return true;
            }
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mmap;
        for(auto w : words){
            mmap[w] += 1;
        }
        vector<pair<int,string> > result;
        result.reserve(mmap.size());
        for(auto it=mmap.begin();it!=mmap.end();++it){
            result.push_back(make_pair(it->second,it->first));
        }
        sort(result.begin(),result.end(),mycompare);
        vector<string> ans(k);
        for(int i=0;i<k;++i){
            ans[i] = result[i].second;
        }
        return ans;
    }
};
