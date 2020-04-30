class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            if(nums[i]==-1){
                continue;
            }
            int current = nums[i];
            while(1){
                int current_index = current-1;
                if(nums[current_index]==-1){
                    //already visited....
                    return current_index+1;
                }else if(current_index==i){
                    nums[current_index] = -1;
                    break;
                }else{
                    int tmp = nums[current_index];
                    nums[current_index] = -1;
                    current = tmp;
                }
            }
        }
        return -1;
    }
};
