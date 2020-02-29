class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX);
        dp[0] = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n&&j<=i+nums[i];j++){
                if(dp[i]!=INT_MAX&&dp[i]+1<dp[j]){
                    dp[j] = dp[i]+1;
                }
            }
        }
        if(dp[n-1]==INT_MAX){
            return false;
        }
        /*for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }*/
        return true;
    }
};
