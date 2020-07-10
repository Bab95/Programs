class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > p;
        p.reserve(nums.size());
        for(int i=0;i<nums.size();++i){
            p.push_back(make_pair(nums[i],i));
        }
        sort(p.begin(),p.end());
        int l = 0,r = p.size()-1;
        while(l<r){
            if(p[l].first+p[r].first==target){
                return {p[l].second,p[r].second};
            }else if(p[l].first+p[r].first>target){
                r--;
            }else{
                ++l;
            }
        }
        return {-1,-1};
    }
};
