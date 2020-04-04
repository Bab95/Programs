class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> my_map;
        for(int i=0;i<nums.size();i++){
            if(my_map.count(nums[i])==0){
                my_map[nums[i]] = 1;
            }else{
                return true;
            }
        }
        return false;
    }
};