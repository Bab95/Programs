class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mmap;
        int sum = 0;
        int result = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                result++;
            }
            if(mmap.count(sum-k)!=0){
                result+=mmap[sum-k];
            }
            mmap[sum]++;
        }
        return result;
    }
};