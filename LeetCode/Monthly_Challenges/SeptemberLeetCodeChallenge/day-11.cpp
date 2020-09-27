class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        dp[0][0] = dp[1][0] = nums[0];
        int ans = nums[0];
        for(int i=1;i<n;++i){
            int current_max = max(dp[0][i-1]*nums[i],dp[1][i-1]*nums[i]);
            dp[0][i] = max(current_max,nums[i]);
            int current_min = min(dp[0][i-1]*nums[i],dp[1][i-1]*nums[i]);
            dp[1][i] = min(current_min,nums[i]);
            ans = max(dp[0][i],ans);
        }
        return ans;
    }
};
