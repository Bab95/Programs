class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int i = 0;
        int ans = INT_MAX;
        int start = 0;
        while(i<nums.size()){
            sum+=nums[i];
            if(sum>=s){
                ans = min(ans,i-start+1);
            }
            while(sum>s){
                sum = sum-nums[start];
                start++;
                if(sum>=s){
                    ans = min(ans,i-start+1);
                }
            }
            ++i;
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};
