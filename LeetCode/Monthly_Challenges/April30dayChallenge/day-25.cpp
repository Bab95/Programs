class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        int maxreach = nums[0];
        int steps = nums[0];
        int jumps = 1;
        for(int i=1;i<n;++i){
            if(steps==0){
                return false;
            }
            maxreach = max(i+nums[i],maxreach);
            steps = maxreach-i;
        }
        return true;
    }
};
