class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0){
            return 1;
        }
        sort(nums.begin(),nums.end());
        int k = 0;
        int ans = 1;
        while(k<nums.size()&&nums[k]<=0){
            k++;
        }
        while(1&&k<nums.size()){
            if(nums[k]==ans){
                while(k<nums.size()&&nums[k]==ans){
                    k++;
                }
                ans++;
            }else{
                return ans;
            }
        }
        return ans;
    }
};
