class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int index = 0;
        int i = 0;
        int k = 0;
        while(i<nums.size()/2){
            int freq = nums[2*i];
            int val = nums[2*i+1];
            i++;
            for(int p = 0;p<freq;++p){
                ans.push_back(val);
            }
        }
        return ans;
    }
};
