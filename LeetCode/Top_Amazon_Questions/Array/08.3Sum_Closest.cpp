class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==target){
                    return target;
                }else if((nums[i]+nums[l]+nums[r]-target)>0){
                    if(abs(nums[i]+nums[l]+nums[r]-target)<diff){
                        diff = abs(nums[i]+nums[l]+nums[r]-target);
                        ans = nums[i]+nums[l]+nums[r];
                    }
                    r--;
                }else if((nums[i]+nums[l]+nums[r]-target)<0){
                    if(abs(nums[i]+nums[l]+nums[r]-target)<diff){
                        diff = abs(nums[i]+nums[l]+nums[r]-target);
                        ans = nums[i]+nums[l]+nums[r];
                    }
                    l++;
                }
            }
        }
        return ans;
    }
};
