class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (arr.size() <= 1){
            return 0;
        }
        int left = 0;
        int right = arr.size()-1;
        while (left + 1 <arr.size() && arr[left] <= arr[left+1]){
            left++;
        }
        while (right > 0 && arr[right-1] <= arr[right]){
            right--;
        }

        if (left > right){
            return 0;
        }
        // cout <<left <<" "<<right<<endl;
        if (arr[left] <= arr[right]) {
            // remove middle potion.
            return right - left - 1;
        }
        int len = arr.size();
        for (int i=left;i >= 0;i--){
            // x will be the index equal or greater than arr[i] so we will have to remove the remaining section.
            int x = lower_bound(arr.begin()+right, arr.end(), arr[i]) - arr.begin();
            len = min(len, x - i - 1);
        }
        for (int i=right;i<arr.size();i++){
            int x = lower_bound(arr.begin(), arr.begin()+left, arr[i]) - arr.begin();
            len = min(len, i-x);
        }
        return len;
    }
};
