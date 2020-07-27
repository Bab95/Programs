class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        vector<int> prefix(nums.size(),0);
        vector<int> suffix(nums.size(),0);
        prefix[0] = nums[0];
        suffix[nums.size()-1] = nums[nums.size()-1];
        for(int i=1;i<nums.size();++i){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i] = suffix[i+1] + nums[i];
        }
        for(int i=0;i<nums.size();++i){
            if(prefix[i]==suffix[i]){
                return i;
            }
        }
        return -1;
    }
};
