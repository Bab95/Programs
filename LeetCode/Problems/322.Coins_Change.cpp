#include <limits.h>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int> > dp;
        int n = coins.size();
        vector<int> tmp(n,INT_MAX);
        for(int i=0;i<=amount;i++){
            dp.push_back(tmp);
        }
        for(int i=0;i<n;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    int include = (dp[i-coins[j]][j]==INT_MAX)?INT_MAX:dp[i-coins[j]][j]+1;
                    int exclude = (j>=1)?dp[i][j-1]:INT_MAX;
                    dp[i][j] = min(include,exclude);

                }else{
                    dp[i][j] = (j>=1)?dp[i][j-1]:INT_MAX;
                }
            }
        }
        if(dp[amount][n-1]==INT_MAX){
            return -1;
        }
        return dp[amount][n-1];
    }
};
