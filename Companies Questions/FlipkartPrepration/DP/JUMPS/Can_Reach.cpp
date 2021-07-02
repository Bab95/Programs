/*Given an array of jumps return true if frog can reach till end taking at max arr[i] no of jumps.*/
/*
TC=>O(n^2)
SC=>O(n)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp;
        int n = nums.size();
        dp.assign(n,false);
        dp[0] = true;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<=i+nums[i]&&j<n;++j){
                dp[j] = dp[j] || dp[i];
            }
        }
        //for(int i=0;i<nums.size();++i){
        //    cout<<dp[i]<<" ";
        //}
        return dp[n-1];
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n&&j<=i+nums[i];++j){
                if(dp[i]!=INT_MAX&&dp[i]+1<dp[j]){
                    dp[j] = dp[i]+1;
                }
            }
        }
        return (dp[n-1]!=INT_MAX);
    }
    /*
    OPTIMIZED SOLUTION
    keep track of maximum reach at any point
    */

    bool canJump(vector<int>& nums) {
        int max_reach = nums[0];
        int steps = nums[0];
        int n = nums.size();
        for(int i=1;i<n;++i){
            if(steps==0){
                return false;
            }
            max_reach = max(max_reach,i+nums[i]);
            steps = max_reach-i;
        }
        return true;
    }
};




