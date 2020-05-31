class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*vector<pair<int,int> > arr;
        arr.reserve(nums.size());
        for(int i=0;i<nums.size();++i){
            arr.push_back(make_pair(nums[i],i));
        }*/
        sort(nums.begin(),nums.end());
        return (nums[nums.size()-2]-1)*(nums[nums.size()-1]-1);
    }
};
