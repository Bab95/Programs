class Solution {
public:
    unsigned long long int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        unsigned long long int dp[m][n];
        /*if(obstacleGrid[0][0]==1){
            return 0;
        }
        dp[0][0] = 1;
        int i = 1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==0){
                dp[i][0] = 1;
            }else{
                dp[i][0] = 0;
            }
        }
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==0){
                dp[0][i] = 1;
            }else{
                dp[0][i] = 0;
            }
        }
        */
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int i = 0;
        while(i<n&&obstacleGrid[0][i]==0){
            dp[0][i] = 1;
            i++;
        }
        while(i<n){
            dp[0][i] = 0;
            i++;
        }
        i = 1;
        while(i<m&&obstacleGrid[i][0]==0){
            dp[i][0] = 1;
            i++;
        }
        while(i<m){
            dp[i][0] = 0;
            i++;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]!=1){
                    unsigned long long int top = (obstacleGrid[i-1][j]==1)?0:dp[i-1][j];
                    unsigned long long int left = (obstacleGrid[i][j-1]==1)?0:dp[i][j-1];
                    dp[i][j] = top+left;
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
