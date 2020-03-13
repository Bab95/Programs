class Solution {
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        if(n==2){
            return 2;
        }
        vector<int> dp(n+1,INT_MAX);
        for(int i=2;i<=n/2;i++){
            if(dp[i]==INT_MAX){
                dp[i] = i;
            }
            for(int j=2*i,k=2;j<=n;j=i*k){
                //if(i>2){
                    dp[j] = min(dp[i]+k,dp[j]);
                //}else{
                    //dp[j] = min(dp[i]+k-1,dp[j]);
                //}
                k++;
            }
        }
        for(int i=n/2;i<=n;i++){
            if(dp[i]==INT_MAX){
                dp[i] = i;
            }
        }
        return dp[n];
    }
};
