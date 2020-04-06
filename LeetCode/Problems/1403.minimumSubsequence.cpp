class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        vector<int> result;
        int sum2 = 0;
        for(int i=nums.size()-1;i>=0;i--){
            if(sum2>sum){
                return result;
            }
            sum2 += nums[i];
            sum -= nums[i];
            result.push_back(nums[i]);
        }
        return result;
    }
};