class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mmap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(mmap.find(target-nums[i])!=mmap.end()){
                ans.push_back(i);
                ans.push_back(mmap[target-nums[i]]);
                sort(ans.begin(),ans.end());
                return ans;
            }else{
                mmap[nums[i]] = i;
            }
        }
        return ans;
    }
};