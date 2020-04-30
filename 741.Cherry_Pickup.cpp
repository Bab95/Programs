// mistake is i have marked every cherry picked need to know which one i picked....


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > dp(n,vector<int>(m));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;++i){
            if((grid[0][i]==1||grid[0][i]==0)&&dp[0][i-1]!=INT_MIN){
                dp[0][i] = dp[0][i-1]+grid[0][i];
                grid[0][i] = 0;
            }else{
                dp[0][i] = INT_MIN;
            }
        }

        for(int i=1;i<n;i++){
            if((grid[i][0]==1||grid[i][0]==0)&&dp[i-1][0]!=INT_MIN){
                dp[i][0] = dp[i-1][0]+grid[i][0];
                grid[i][0] = 0;
            }else{
                dp[i][0] = INT_MIN;
            }
        }

        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                if(grid[i][j]==-1){
                    dp[i][j] = INT_MIN;
                    continue;
                }else if(grid[i][j]==0){
                    int left = dp[i-1][j];
                    int top = dp[i][j-1];
                    dp[i][j] = (max(left,top)!=INT_MIN)?max(left,top):INT_MIN;
                }else if(grid[i][j]==1){
                    int left = dp[i-1][j];
                    int top = dp[i][j-1];
                    dp[i][j] = (max(left,top)!=INT_MIN)?(max(left,top)+1):INT_MIN;
                    grid[i][j] = (dp[i][j]!=INT_MIN)?0:1;
                }
            }
        }

        if(dp[n-1][m-1]!=INT_MIN){
            for(int i=m-2;i>=0;i--){
                if((grid[n-1][i]==1||grid[n-1][i]==0)&&dp[n-1][i+1]!=INT_MIN){
                    dp[n-1][i] = dp[n-1][i+1] + grid[n-1][i];
                    grid[n-1][i] = 0;
                }else{
                    dp[n-1][i] = INT_MIN;
                }


            }

            for(int i=n-2;i>=0;i--){
                if((grid[i][m-1]==1||grid[i][m-1]==0)&&dp[i+1][m-1]!=INT_MIN){
                    dp[i][m-1] = dp[i+1][m-1] + grid[i][m-1];
                    grid[i][m-1] = 0;
                }else{
                    dp[i][m-1] = INT_MIN;
                }
            }

            for(int i=n-2;i>=0;i--){
                for(int j=m-2;j>=0;j--){
                    if(grid[i][j]!=-1){
                        int right = dp[i+1][j];
                        int down = dp[i][j+1];
                        dp[i][j] = (max(right,down)!=INT_MIN)?(max(right,down)+grid[i][j]):INT_MIN;
                        grid[i][j] = (dp[i][j]!=INT_MIN)?0:grid[i][j];
                    }else{
                        dp[i][j] = INT_MIN;
                    }
                }
            }
            cout<<"okay";
            return dp[0][0];
        }else{
            cout<<"from";
            return 0;
        }
        //int result = max(0,dp[n-1][m-1]);
        cout<<"from here";
        return 0;

    }
};
