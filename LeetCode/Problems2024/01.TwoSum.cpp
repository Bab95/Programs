class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> mmap;
        for (int i=0;i<nums.size();i++) {
            if (mmap.find(target-nums[i]) != mmap.end()) {
                result.push_back(i);
                result.push_back(mmap[target-nums[i]]);
            } else {
                mmap[nums[i]] = i;
            }
        }
        return result;
    }
};
