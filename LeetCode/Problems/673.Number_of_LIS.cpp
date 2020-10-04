class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        vector<pair<int,int> > dp(nums.size(),{1,1});
        int len = 1;
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]&&dp[j].first+1>=dp[i].first){
                    if(dp[i].first==dp[j].first+1){
                        dp[i].second += dp[j].second;
                    }else{
                        dp[i].second = dp[j].second;
                    }
                    dp[i].first = dp[j].first + 1;
                }
            }
            len = max(len,dp[i].first);
        }
        int res = 0;
        for(int i=0;i<dp.size();++i){
            if(len==dp[i].first){
                res+=dp[i].second;
            }
        }
        return res;
    }
};
