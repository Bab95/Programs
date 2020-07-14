class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<long int> count(nums[nums.size()-1]+1,0);
        for(int i=0;i<nums.size()-1;++i){
            for(int j=i+1;j<nums.size();++j){
                count[nums[j]-nums[i]]++;
            }
        }
        long int c = 0;
        for(int i=0;i<count.size();++i){
            c+=count[i];
            if(c>=k){
                return i;
            }
        }
        return -1;
    }
};
