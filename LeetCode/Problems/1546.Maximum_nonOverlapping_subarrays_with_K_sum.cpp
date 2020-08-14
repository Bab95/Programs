class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> ss;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            if(ss.find(sum-target)!=ss.end()||sum==target){
                ans++;
                ss.clear();
                sum = 0;
            }else{
                ss.insert(sum);
            }
        }
        return ans;
    }
};
