class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1){
            return nums;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        pair<int,int> res;
        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            if(dp[i]>res.first){
                res.first = dp[i];
                res.second = i;
            }
        }
        vector<int> ans;
        int val = nums[res.second];
        for(int i=res.second;i>=0;i--){
            if(val%nums[i]==0&&dp[i]==res.first){
                val = nums[i];
                ans.push_back(nums[i]);
                res.first--;
            }
        }
        return ans;
    }
};
