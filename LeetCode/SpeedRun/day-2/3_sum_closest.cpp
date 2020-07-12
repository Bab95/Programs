class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int diff = INT_MAX;
        for(int i=0;i<nums.size()-2;++i){
            int l = i + 1;
            int r = nums.size()-1;
            while(l<r){
                int current = nums[i]+nums[l]+nums[r];
                if(current==target){
                    return target;
                }
                if(abs(current-target)<diff){
                    ans = current;
                    diff = abs(current-target);
                }
                if(current>target){
                    --r;
                }else{
                    ++l;
                }
            }
        }
        return ans;
    }
};
