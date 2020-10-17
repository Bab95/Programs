class Solution {
public:
    int numWays(int n, int k) {
        if(n==0||k==0){
            return 0;
        }
        if(n==1){
            return k;
        }
       vector<int> dp(n+1,0);
        dp[1] = k;
        dp[2] = k + (k-1)*k;
        for(int i=3;i<=n;++i){
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] *= (k-1);
        }
        return dp[n];
    }
};
