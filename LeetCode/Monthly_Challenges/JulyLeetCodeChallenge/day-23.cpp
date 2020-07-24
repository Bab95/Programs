class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int _xor = nums[0];
        for(int i=1;i<nums.size();++i){
            _xor ^= nums[i];
        }
        int bit = _xor&(~(_xor-1));
        int x1 = 0,x2 = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]&bit){
                x1 ^= nums[i];
            }else{
                x2 ^= nums[i];
            }
        }
        return {x1,x2};
    }
};
