class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // unordered_set requires to define a hash function
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size();i++) {
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                if (nums[i] + nums[start] + nums[end] == 0) {
                    result.insert({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                } else if(nums[i] + nums[start] + nums[end] > 0) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        vector<vector<int>> res(result.begin(), result.end());
        return res;
    }
};
