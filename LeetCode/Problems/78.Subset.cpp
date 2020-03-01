class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int powsize = (int)pow(2,n);
        vector<vector<int> > result;
        for(int i=powsize-1;i>=0;i--){
            int tmp = i;
            vector<int> subset;
            int j = 0;
            while(tmp){
                if(tmp&1){
                    subset.push_back(nums[j]);
                }
                tmp = tmp/2;
                j++;
            }
            result.push_back(subset);
        }
        return result;
    }
};
