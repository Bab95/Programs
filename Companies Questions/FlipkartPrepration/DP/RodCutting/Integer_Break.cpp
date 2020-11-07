class Solution {
public:
    int dfs(int n,vector<int>& dp){
        if(n==1){
            return 1;
        }
        if(dp[n]!=INT_MIN){
            return dp[n];
        }
        int max_val = INT_MIN;
        for(int i=1;i<n;++i){
            max_val = max(max_val,max(i*dfs(n-i,dp),i*(n-i)));
        }
        return dp[n] = max_val;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,INT_MIN);
        return dfs(n,dp);
    }
};