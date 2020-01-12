class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
        }
        int result = min(dp[n-2],dp[n-1]);
        return result;
    }
};
