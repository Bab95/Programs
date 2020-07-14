class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size()-1;
        while(index>0&&nums[index-1]>=nums[index]){
            index--;
        }
        if(index==0){
            sort(nums.begin(),nums.end());
            return;
        }
        int current = nums[index-1];
        int swap_index = index;
        for(int i=index;i<nums.size();++i){
            if(nums[i]>current&&nums[i]<=nums[swap_index]){
                swap_index = i;
            }
        }
        swap(nums[index-1],nums[swap_index]);
        sort(nums.begin()+index,nums.end());
    }
};
