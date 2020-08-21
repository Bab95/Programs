class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> arr(nums.size(),0);
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
        int _max = INT_MIN;
        for(int i=0;i<nums.size();++i){
            pq.push(make_pair(nums[i][0],i));
            _max = max(_max,nums[i][0]);
        }
        int range = INT_MAX;
        int _min = INT_MAX;
    priority_queue<int,vector<int>,greater<int> > prev_values;
        vector<int> ans(2);
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int row = it.second;
            int val = it.first;
            int next = INT_MIN;
            if(arr[row]<nums[row].size()-1){
                //this array is all used....
                next = nums[row][arr[row]+1];
                arr[row] += 1;
                pq.push({next,row});
            }else if(arr[row]==nums[row].size()-1){
                //no insertion at this point...
                prev_values.push(val);
            }
            int prev = INT_MAX;
            if(!prev_values.empty()){
                prev = prev_values.top();
            }
            _min = min(prev,val);
            int current = _max-_min;
            if(current<range){
                range = current;
                ans[0] = _min;
                ans[1] = _max;
            }
            _max = max(_max,next);
        }
        return ans;
    }
};
