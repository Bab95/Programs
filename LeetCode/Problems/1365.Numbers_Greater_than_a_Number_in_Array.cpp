class Solution {
public:
    struct Comparator{
        bool operator()(pair<int,int> const& p1,pair<int,int> const& p2){
            return p1.first<p2.first;       
        }
    };
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >,Comparator >  pq;
        pair<int,int> p;
        for(int i=0;i<nums.size();++i){
            p.first = nums[i];
            p.second = i;
            pq.push(p);
        }
        vector<int> ans(nums.size());
        //ans.reserve(nums.size());
        stack<int> stk;
        while(!pq.empty()&&pq.size()>1){
            p = pq.top();
            pq.pop();
            stk.push(p.second);
            while(!pq.empty()&&pq.top().first==p.first){
                stk.push(pq.top().second);
                pq.pop();
            }
            while(!stk.empty()){
                ans[stk.top()] = pq.size();
                stk.pop();
            }
        }
        ans[pq.top().second] = 0;
        return ans;
    }
};