class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int> > result;
        for(int i=0;i<=n-3;++i){
            int l = i+1;
            int r = n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    result.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<n&&nums[l]==nums[l-1]){
                        ++l;
                    }
                    while(r>=0&&nums[r]==nums[r+1]){
                        --r;
                    }
                }else if(nums[i]+nums[l]+nums[r]>0){
                    --r;
                }else{
                    ++l;
                }
            }

            while(i<n-1&&nums[i]==nums[i+1]){
                ++i;
            }
        }
        return result;
    }
};
