class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        int max_len = dp[0];
        for(int i=1;i<n;i++){
            max_len = max(max_len,dp[i]);
        }
        return max_len;
    }
};
