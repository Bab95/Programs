class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_product(n,0),min_product(n,0);
        int ans = nums[0];
        max_product[0] = nums[0];
        min_product[0] = nums[0];
        for(int i=1;i<n;++i){
            int current = max(nums[i]*max_product[i-1],nums[i]*min_product[i-1]);
            max_product[i] = max(current,nums[i]);
            current = min(nums[i]*min_product[i-1],nums[i]*max_product[i-1]);
            min_product[i] = min(current,nums[i]);
            ans = max(ans,max_product[i]);
        }
        return ans;
    }
};
