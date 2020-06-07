class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> tmp(n),tmp2(n);
        for(int i=0;i<n;++i){
            tmp[i] = nums[i];
            tmp2[i] = nums[i+n];
        }
        int i = 0;
        int j = 0;
        int index = 0;
        while(i<n&&index<nums.size()){
            nums[index++] = tmp[i++];
            nums[index++] = tmp2[j++];
        }
        return nums;
    }
};
