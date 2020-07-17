class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mmap;
        for(int i=0;i<nums.size();++i){
            mmap[nums[i]] += 1;
        }
        set<pair<int,int> > ss;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if(ss.size()<k){
                ss.insert(make_pair(it->second,it->first));
            }else{
                if(it->second>ss.begin()->first){
                    ss.erase(ss.begin());
                    ss.insert(make_pair(it->second,it->first));
                }
            }
        }
        vector<int> ans;
        while(!ss.empty()){
            ans.push_back(ss.begin()->second);
            ss.erase(ss.begin());
        }
        return ans;
    }
};
