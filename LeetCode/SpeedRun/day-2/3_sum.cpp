class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){
            return {};
        }
        sort(nums.begin(),nums.end());
        set<vector<int> > ss;
        for(int i=0;i<nums.size()-2;++i){
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    ss.insert({nums[i],nums[l],nums[r]});
                    ++l;
                    --r;
                }else if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }else{
                    ++l;
                }
            }
        }
            vector<vector<int> > ans(ss.begin(),ss.end());
            return ans;
    }
};
