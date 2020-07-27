class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_set<int> s;
        int ans = INT_MIN;
        vector<bool> visited(nums.size(),false);
        for(int i=0;i<nums.size();++i){
            if(visited[i]){
                continue;
            }
            s.clear();
            int current = nums[i];
            s.insert(current);
            visited[current] = true;
            while(1){
                int next = nums[current];
                if(s.count(next)!=0){
                    ans = max(ans,(int)s.size());
                    break;
                }else{
                    visited[next] = true;
                    s.insert(next);
                    current = next;
                }
            }
        }
        return ans;
    }
};
