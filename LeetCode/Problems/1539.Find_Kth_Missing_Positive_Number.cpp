class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<bool> nums(1001,false);
        for(int i=0;i<arr.size();++i){
            nums[arr[i]] = true;
        }
        for(int i=1;i<=1000;++i){
            if(!nums[i]){
                k--;
                if(k==0){
                    return i;
                }
            }
        }
        int ans = 1000;
        while(k--){
            ans++;
        }
        return ans;
    }
};
