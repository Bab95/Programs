class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mmap;
        for(int i=0;i<nums.size();++i){
            mmap[nums[i]]+=1;
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if(pq.size()<k){
                pq.push(make_pair(it->second,it->first));
            }else{
                if(it->second>pq.top().first){
                    pq.pop();
                    pq.push(make_pair(it->second,it->first));
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
