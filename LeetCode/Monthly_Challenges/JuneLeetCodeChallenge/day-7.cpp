class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        int n = amount;
        int m = coins.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                if(i==0){
                    dp[i][j] = 0;
                }else if(j==0){
                    dp[i][j] = 1;
                }else if(coins[i-1]<=j){
                    int include = dp[i][j-coins[i-1]];
                    int exclude = dp[i-1][j];
                    dp[i][j] = include + exclude;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
