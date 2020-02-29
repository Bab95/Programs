class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int current_max = nums[0];
        for(int i=1;i<nums.size();i++){
            current_max = max(current_max+nums[i],nums[i]);
            max_so_far = max(max_so_far,current_max);
        }
        return max_so_far;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
    int min(int a,int b){
        return a<b?a:b;
    }
};
