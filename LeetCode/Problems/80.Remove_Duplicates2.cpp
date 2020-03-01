class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
        for(int i=0;i<nums.size();i++,length++){
            if(length>=2&&nums[i]==nums[length-2]){
                length--;
            }
            nums[length] = nums[i];
        }
        return length;
    }
};
