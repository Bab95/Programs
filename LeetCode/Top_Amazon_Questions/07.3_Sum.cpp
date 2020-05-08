class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        if(nums.size()<3){
            return result;
        }

        sort(nums.begin(),nums.end());

        for(int i:nums){
            cout<<i<<" ";
        }

        for(int i=0;i<nums.size()-2;++i){

            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    result.push_back({nums[i],nums[l],nums[r]});
                    while(l<r&&nums[l]==nums[l+1]){
                        l++;
                    }
                    l++;
                    while(r>l&&nums[r]==nums[r-1]){
                        r--;
                    }
                    r--;
                }else if(nums[i]+nums[l]+nums[r]>0){
                     while(r>l&&nums[r]==nums[r-1]){
                        r--;
                    }
                    r--;
                }else{
                    while(l<r&&nums[l]==nums[l+1]){
                        l++;
                    }
                    l++;
                }
            }

            while(i<nums.size()-2&&nums[i]==nums[i+1]){
                i++;
            }

        }
        return result;
    }
};
