class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_so_far = INT_MIN;
        int max_ending_here = 0;
        for (int i=0;i<nums.size();i++){
            max_ending_here += nums[i];
            if (max_ending_here > max_so_far){
                max_so_far = max_ending_here;
            }
            if (max_ending_here < 0){
                max_ending_here = 0;
            }
        }
        int min_so_far = INT_MAX;
        int min_ending_here = 0;
        for (int i=0;i<nums.size();i++){
            min_ending_here += nums[i];
            if (min_ending_here > 0){
                min_ending_here = 0;
            }
            if (min_ending_here < min_so_far){
                min_so_far = min_ending_here;
            }
        }
        return max(max_so_far, abs(min_so_far));
    }
};