class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
       int start = 0;
        int i = 1;
        while(i<nums.size()){
            while(i<nums.size()&&nums[i]==nums[start]){
                i++;
            }
            if(i!=nums.size()){
                nums[start+1] = nums[i];
                start++;
                i++;
            }
        }
        return start+1;
    }
};
