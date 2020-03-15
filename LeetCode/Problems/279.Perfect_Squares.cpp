class Solution {
public:
    int numSquares(int n) {
        vector<int> sqrs;
        int i = 1;
        for(i=1;i*i<=n;i++){
            sqrs.push_back(i*i);
        }
        int n_s = sqrs.size();
        //int dp[n_s+1][n+1];
        int INF = 100000;
        vector<vector<int> > dp(n_s+1,vector<int>(n+1,INF));
        /*for(int i=0;i<=n_s;i++){
            for(int j=0;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=0;i<=n_s;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i] = INF;
            //dp[1][i] = i;
        }
        /*
        for(int i=0;i<=n_s;i++){
            for(int j=0;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=1;i<=n_s;i++){
            for(int j=1;j<=n;j++){
                if(j>=sqrs[i-1]){
                    int inc = dp[i][j-sqrs[i-1]] + 1;
                    int exc = dp[i-1][j];
                    dp[i][j] = min(inc,exc);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        /*for(int i=0;i<=n_s;i++){
            for(int j=0;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return dp[n_s][n];
    }
};
