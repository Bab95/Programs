class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0;i<=n-3;++i){
            int l = i+1;
            int r = n-1;

            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==target){
                    return target;
                }else if(sum>target){
                    r--;
                }else{
                    ++l;
                }
                if(abs(ans-target)>abs(sum-target)){
                    ans = sum;
                }
            }
        }
        return ans;
    }
};
