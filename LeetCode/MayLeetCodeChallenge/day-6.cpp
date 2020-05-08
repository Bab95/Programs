class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mmap;
        for( int x : nums){
            mmap[x]+=1;
        }
        int n = nums.size();
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if(it->second>n/2){
                return it->first;
            }
        }
        return -1;
    }
};
