class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==1){
            return (target == nums[0])?0:-1;
        }
        int low = 0;
        int high = nums.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target){
                return mid;
            }
            // we are in the second half of array 4 5 6 7 0 1 [2] 3
            if (nums[mid] < nums[0]) {
                if (nums[mid] < target) {
                    if (target < nums[0]){
                        low = mid+1;
                    }else{
                        high = mid;
                    }
                }else{
                    high = mid;
                }
            }else {
                if (target < nums[mid]){
                    if (target >= nums[0]){
                        high = mid;
                    }else{
                        low = mid+1;
                    }
                }else{
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};
