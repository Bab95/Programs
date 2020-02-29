class Solution {
public:
    int jump(vector<int>& nums) {
        /*vector<int> dp(nums.size(),INT_MAX);
        dp[0] = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n&&j<=i+nums[i];j++){
                if(dp[i]!=INT_MAX&&dp[j]>dp[i]+1){
                    dp[j] = dp[i]+1;
                }
            }
        }
        /*
        for(int i=0;i<=n;i++){
            cout<<dp[i]<<" ";
        }*/
        if(nums.size()==1){
            return 0;
        }
        int position = nums[0];
        int max_reach = nums[0];
        int jumps = 1;
        for(int i=1;i<nums.size();i++){
            if(position<i){
                jumps++;
                position = max_reach;
            }
            max_reach = max(max_reach,i+nums[i]);
        }
        return jumps;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
};
