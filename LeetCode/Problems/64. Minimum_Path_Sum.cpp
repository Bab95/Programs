class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        //cout<<m<<" "<<n<<endl;
        vector<vector<int> > dp;
        vector<int> tmp(n);
        for(int i=0;i<m;i++){
            dp.push_back(tmp);
        }
        dp[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
