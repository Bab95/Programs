class Solution {
public:
    int numSquares(int n) {
        vector<int> square;
        for(int i=1;i*i<=n;++i){
            square.push_back(i*i);
        }
        int m = square.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;++i){
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;++i){
            dp[0][i] = INT_MAX;
        }
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(j>=square[i-1]){
                    int include = dp[i][j-square[i-1]] + 1;
                    int exclude = dp[i-1][j];
                    dp[i][j] = min(include,exclude);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
