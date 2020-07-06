class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();
        vector<int> sum(n,0);
        sum[0] = nums[0];
        sum[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;++i){
            if(nums[i]+sum[i-2]>sum[i-1]){
                sum[i] = nums[i]+sum[i-2];
            }else{
                sum[i] = sum[i-1];
            }
        }
        return sum[n-1];
    }
};
