class Solution{
	public:

		int DivisibleByM(vector<int>nums, int m){
		    // Code here
		    int n = nums.size();
		    if(n>=m){
		        return 1;
		    }
		    vector<bool> dp(m,false);
		    for(int i=0;i<n;++i){
		        if(dp[0]){
		            return true;
		        }
		        vector<bool> tmp(m,false);
		        for(int j=0;j<m;++j){
		            if(dp[j]==true){
		                if(dp[(j+nums[i])]==false)
		                    tmp[(j+nums[i])%m] = true;
		            }
		        }
		        for(int j=0;j<m;++j){
		            if(tmp[j]){
		                dp[j] = true;
		            }
		        }
		        dp[nums[i]%m] = true;
		    }
		    return dp[0];
		}
};