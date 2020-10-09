class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k==0){
            for(int i=0;i<nums.size();++i){
                if(nums[i]==k&&i<nums.size()-1&&nums[i+1]==k){
                    return true;
                }
            }
            return false;
        }
        unordered_map<int,int> mmap;
        int sum = 0;
        mmap[0] = -1;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            int rem;
            if(k!=0){
                rem = sum%k;

                if(mmap.find(rem)==mmap.end()){
                    mmap[rem] = i;
                }else{
                    if(i-mmap[rem]>=2){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
