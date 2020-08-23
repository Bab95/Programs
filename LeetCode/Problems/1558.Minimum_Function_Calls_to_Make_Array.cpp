class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        while(true){
            for(int i=0;i<n;++i){
                if(nums[i]%2==1){
                    ans++;
                    nums[i]--;
                }
            }
            bool flag = false;
            for(int i=0;i<n;++i){
                if(nums[i]){
                    ans++;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                return ans;
            }
            for(int i=0;i<n;++i){
                nums[i] /= 2;
            }
        }
        return ans;
    }
};
