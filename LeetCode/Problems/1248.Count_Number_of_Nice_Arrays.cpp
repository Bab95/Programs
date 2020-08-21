class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(nums.size()==0){
            return 0;
        }
        int sum = 0;
        unordered_map<int,int> mmap;
        mmap[0] = 1;
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            sum += (nums[i]%2);
            mmap[sum] += 1;
            if(mmap.find(sum-k)!=mmap.end()){
                ans += mmap[sum-k];
            }
        }
        return ans;

    }
};
