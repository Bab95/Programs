class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mmap;
        for(int i=0;i<nums.size();++i){
            mmap[nums[i]] += 1;
        }
        sort(nums.begin(),nums.end(),[&](int& a,int& b){
            if(a==b){
                return false;
            }
            if(mmap[a]==mmap[b]){
               return a>b;
           }
            return mmap[a]<mmap[b];
        });
        return nums;
    }
};
