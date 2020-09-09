class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long int a = (long int)nums[0]*(long int)nums[1]*(long int)nums[n-1]; // incase of big negaive numbers
        long int b = (long int)nums[n-1]*(long int)nums[n-2]*(long int)nums[n-3];

        return  max(a,b);
    }
};
