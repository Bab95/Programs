typedef long long int ll;
class Solution {
public:
    const ll M = 1000000007;
    int combinationSum4(vector<int>& nums, int target) {
        vector<ll> dp(target+1,0);
        dp[0] = 1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;++i){
            for(int j=0;j<nums.size();++j){
                if(i-nums[j]>=0){
                    dp[i] += dp[i-nums[j]];
                }else{
                    break;
                }
                if(dp[i]>=INT_MAX){
                    dp[i] = dp[i]%M;
                }
            }
        }
        return dp[target];
    }
};
