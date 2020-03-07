class Solution {
public:
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int powsize = pow(2,n);
        sort(nums.begin(),nums.end());
        unordered_set<vector<int>,VectorHash > result;
        for(int i=powsize-1;i>=0;i--){
            int tmp = i;
            vector<int> subres;
            int j = 0;
            while(tmp){
                if(tmp&1){
                    subres.push_back(nums[j]);
                }
                tmp = tmp>>1;
                j++;
            }
            //if(subres.size()>0)
            result.insert(subres);
        }
        vector<vector<int> > final_res(result.size());
        int k = 0;
        for(unordered_set<vector<int> >::iterator itr=result.begin();itr!=result.end();itr++){
            final_res[k++] = *itr;
        }
        return final_res;
    }
};
