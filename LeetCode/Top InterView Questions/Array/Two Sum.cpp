class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > vec(nums.size());
        for(int i=0;i<nums.size();i++){
            vec[i].first = nums[i];
            vec[i].second = i;
        }
        sort(vec.begin(),vec.end());
        int l = 0,r = vec.size()-1;
        vector<int> result;
        while(l<r){
            if(vec[l].first+vec[r].first==target){
                result.push_back(vec[l].second);
                result.push_back(vec[r].second);
                sort(result.begin(),result.end());
                return result;
            }else if(vec[l].first+vec[r].first>target){
                r--;
            }else{
                l++;
            }
        }
        return result;
    }
};