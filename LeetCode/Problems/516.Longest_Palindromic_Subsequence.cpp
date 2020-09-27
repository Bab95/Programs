/*
LCS for string s and its reverser
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string str(s);
        reverse(str.begin(),str.end());
        int n = s.length();
        vector<vector<int> > dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                if(i==0||j==0){
                    dp[i][j] = 0;
                }else if(s[i-1]==str[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][n];
    }
};
