class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n_xor = 0;
        int a_xor = 0;
        for(int i=0;i<=nums.size();++i){
            n_xor ^= i;
        }
        for(int i=0;i<nums.size();++i){
            a_xor ^= nums[i];
        }
        return n_xor^a_xor;
    }
};
