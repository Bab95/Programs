class Solution {
public:
    int abs (int a) {
        if (a < 0) {
            return -1*a;
        }
        return a;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        int result = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size()-2;i++) {
            int start = i+1;
            int end = nums.size()-1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target) {
                    min_diff = 0;
                    return target;
                } else if (sum < target) {
                    if (abs(target-sum) < min_diff) {
                        min_diff = abs(target-sum);
                        result = sum;
                    }
                    start++;
                } else {
                    if (abs(target-sum) < min_diff) {
                        min_diff = abs(target-sum);
                        result = sum;
                    }
                    end--;
                }
            }
        }
        return result;
    }
};
