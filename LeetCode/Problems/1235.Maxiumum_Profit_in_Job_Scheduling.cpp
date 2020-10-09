class Solution {
public:
    struct job{
        int start,end,profit;
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& _profit) {
        int n = startTime.size();
        vector<job> jobs(n);
        for(int i=0;i<n;++i){
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = _profit[i];
        }
        sort(jobs.begin(),jobs.end(),[](auto const& j1,auto const& j2){
            return j1.end<j2.end;
        });
        vector<int> dp(n,0);
        dp[0] = jobs[0].profit;
        for(int i=1;i<n;++i){
            int p = i-1;
            while(p>=0&&jobs[p].end>jobs[i].start){
                p--;
            }
            int prev = 0;
            if(p>=0&&jobs[p].end<=jobs[i].start){
                prev = dp[p];
            }
            dp[i] = max(dp[i-1],prev+jobs[i].profit);
        }
        return dp[n-1];
    }
};
