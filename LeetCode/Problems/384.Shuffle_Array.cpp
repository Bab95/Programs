class Solution {
public:
    vector<int> copy_nums;
    int n;
    Solution(vector<int>& nums) {
        copy_nums.insert(copy_nums.begin(),nums.begin(),nums.end());
        n = nums.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return copy_nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        unordered_map<int,int> mmap;
        vector<int> result(n,0);
        for(int i=0;i<copy_nums.size();){
            int index = rand()%n;
            if(mmap.find(index)==mmap.end()){
                mmap[index] = copy_nums[i];
                ++i;
            }else{
                continue;
            }
        }
        for(auto it=mmap.begin();it!=mmap.end();++it){
            result[it->first] = it->second;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
