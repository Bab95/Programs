class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0){
            return;
        }
        int i = nums.size()-1;
        //while decreasing move i.....
        while(i>0&&nums[i-1]>=nums[i]){
            i--;
        }
        // its already in reverse order
        if(i==0){
            sort(nums.begin(),nums.end());
            return;
        }
        int current = nums[i-1];
        //now find number just greater than this and swap with it...
        int index = i;
        for(int j=i;j<nums.size();++j){
            if(nums[j]>current){
                index = j;
            }
        }
        swap(nums[i-1],nums[index]);
        sort(nums.begin()+i,nums.end());
        return;
    }
};
