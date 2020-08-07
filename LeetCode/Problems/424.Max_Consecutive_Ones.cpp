class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int current = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                ans = max(current,ans);
                current = 0;
            }else{
                current++;
            }
        }
        return max(ans,current);
    }
};
