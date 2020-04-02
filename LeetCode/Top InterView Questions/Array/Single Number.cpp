class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int target = nums[0];
        for(int i=1;i<nums.size();i++){
            target ^= nums[i];
        }
        return target;
    }
};
