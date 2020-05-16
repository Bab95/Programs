class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //unordered_map<int,int> mmap;
        vector<int> hash(10001,0);
        int max_number = nums[0];
        int min_number = nums[0];
        for(int i=0;i<nums.size();++i){
            hash[nums[i]]++;
            max_number = max(max_number,nums[i]);
            min_number = min(min_number,nums[i]);
        }
        vector<int> ans(2);
        for(int i=1;i<=max_number;++i){
            if(hash[i]==2){
                ans[0] = i;
            }
            if(hash[i]==0){
                ans[1] = i;
            }
        }
        if(ans[1]==0){
            ans[1] = max_number+1;
        }
        return ans;
    }
};
