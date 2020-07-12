class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            return {};
        }
        sort(nums.begin(),nums.end());
        set<vector<int> > ss;
        for(int i=0;i<nums.size()-3;++i){
            for(int j=i+1;j<nums.size()-2;++j){
                int l = j+1;
                int r = nums.size()-1;
                int current = nums[i]+nums[j];
                while(l<r){
                    if(current+nums[l]+nums[r]==target){
                        ss.insert({nums[i],nums[j],nums[l],nums[r]});
                        ++l;
                        --r;
                    }else if(current+nums[l]+nums[r]>target){
                        --r;
                    }else{
                        ++l;
                    }
                }
            }
        }
        vector<vector<int> > ans(ss.begin(),ss.end());
        return ans;
    }
};
