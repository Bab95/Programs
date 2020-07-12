class Solution {
public:
    bool isMatch(string s, string p) {
        /*if(s.length()==0||p.length()==0){
            return false;
        }*/
        if(p.length()==0&&s.length()>0){
            return false;
        }
        int m = s.length();
        int n = p.length();

        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
        //base case...
        dp[0][0] = true;

        for(int i=1;i<=n;++i){
            if(p[i-1]=='*'){
                dp[0][i] = dp[0][i-2];
            }
        }

        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-2];//counting s* as nothing.... ie ignoring....
                    if(p[j-2]=='.'||s[i-1]==p[j-2]){
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }

                }else if(s[i-1]==p[j-1]||p[j-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
