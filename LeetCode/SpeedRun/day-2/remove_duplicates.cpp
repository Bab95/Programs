class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int index = 0;
        int i = 0;
        while(i<nums.size()){
            int current = nums[i];
            while(i<nums.size()&&nums[i]==current){
                i++;
            }
            nums[index] = current;
            index++;
        }
        return index;
    }
};
