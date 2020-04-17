class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mmap;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(mmap.count(nums[i])==0){
                mmap[nums[i]] = i;
            }else{
                int diff = i - mmap[nums[i]];
                if(diff<=k){
                    return true;
                }else{
                    //as diff is already large previous can't be the ans...
                    mmap[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
