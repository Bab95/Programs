class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        auto it = lower_bound(nums.begin(),nums.end(),val);
        int index = it-nums.begin();
        if(index>=nums.size()){
            return nums.size();
        }
        int current = nums[index];
        if(current!=val){
            return nums.size();
        }
        int i = index;
        while(i<nums.size()&&nums[i]==current){
            i++;
        }
        while(i<nums.size()){
            nums[index++] = nums[i++];
        }
        return index;
    }
};
