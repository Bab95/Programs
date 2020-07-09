class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;++i){
            int l = i+1;
            int r = n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    ans.insert({nums[i],nums[l],nums[r]});
                    ++l;
                    --r;
                }else if(nums[i]+nums[l]+nums[r]>0){
                    --r;
                }else{
                    ++l;
                }
            }
        }
        vector<vector<int> > res;
        res.insert(res.begin(),ans.begin(),ans.end());
        return res;
    }
};
