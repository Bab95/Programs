class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,0);
        //dp[1] = costs[1];
        for(int i=0;i<days.size();++i){
            dp[days[i]] = costs[0];
        }
        for(int i=1;i<=365;++i){
            if(dp[i]==0){
                dp[i] = dp[i-1];
            }else{
                dp[i] = dp[i-1] + costs[0];
                dp[i] = min(dp[max(i-7,0)]+costs[1],dp[i]);
                dp[i] = min(dp[max(i-30,0)]+costs[2],dp[i]);
            }
        }
        for(int i=1;i<=365;++i){
            cout<<dp[i]<<" ";
        }
        return dp[365];
    }
};
