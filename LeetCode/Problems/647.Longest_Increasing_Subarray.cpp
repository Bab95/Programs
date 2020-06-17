class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==0){
            return 0;
        }
        vector<int> dp(n,1);
        int ans = 1;
        for(int i=1;i<n;++i){
            if(nums[i]>nums[i-1]){
                dp[i] = dp[i-1] + 1;
                ans = max(dp[i],ans);
            }
        }
        return ans;
    }
};
