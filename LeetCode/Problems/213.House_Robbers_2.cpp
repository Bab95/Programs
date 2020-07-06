class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==1){
            return max(nums[0],nums[1]);
        }
        int n = nums.size();
        vector<int> sum1(n,0);
        vector<int> sum2(n,0);
        sum1[1] = nums[1];
        for(int i=2;i<n;++i){
            if(nums[i]+sum1[i-2]>sum1[i-1]){
                sum1[i] = sum1[i-2] + nums[i];
            }else{
                sum1[i] = sum1[i-1];
            }
        }
        sum2[0] = nums[0];
        sum2[1] = max(nums[0],nums[1]);
        for(int i=2;i<n-1;++i){
            if(nums[i]+sum2[i-2]>sum2[i-1]){
                sum2[i] = sum2[i-2] + nums[i];
            }else{
                sum2[i] = sum2[i-1];
            }
        }
        return max(sum1[n-1],sum2[n-2]);
    }
};
