class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        int n = nums.size();
        long int N = pow(2,n)-1;
        vector<vector<int> > ans;
        ans.reserve(N);
        for(int i=0;i<=N;++i){
            int now = i;
            int m = 1;
            int j = i;
            int bit = 0;
            vector<int> current;
            while(j){
                if(j&m){
                    current.push_back(nums[bit]);
                }
                j = j>>1;
                bit++;
            }
            ans.push_back(current);
        }
        return ans;
    }
};
