class Solution {
public:
    int minStartValue(vector<int>& nums) {
        vector<int> sum(nums.size(),0);
        sum[0] = nums[0];
        int min_val = sum[0];
        for(int i=1;i<nums.size();++i){
            sum[i] = sum[i-1]+nums[i];
            min_val = min(sum[i],min_val);
        }
        if(min_val>=0){
            return 1;
        }
        return abs(min_val)+1;
    }
};
