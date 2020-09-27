class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0&&nums[i]<=nums[i-1]){
            i--;
        }
        if(i==0){
            sort(nums.begin(),nums.end());
            return;
        }
        int current = nums[i-1];
        int diff = abs(nums[i]-nums[i-1]);
        int p = i;
        for(int j=i;j<nums.size();++j){
            if(nums[j]>current){
                if(abs(nums[j]-current)<diff){
                    diff = abs(nums[i]-current);
                    p = j;
                }
            }
        }
        swap(nums[i-1],nums[p]);
        sort(nums.begin()+i,nums.end());
    }
};