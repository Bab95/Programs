class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > arr(nums.size());
        for(int i=0;i<nums.size();++i){
            arr[i].first = nums[i];
            arr[i].second = i;
        }
        sort(arr.begin(),arr.end());
        int l = 0;
        int r = arr.size()-1;
        vector<int> ans(2);
        while(l<r){
            if(arr[l].first+arr[r].first==target){
                ans[0] = arr[l].second;
                ans[1] = arr[r].second;
                sort(ans.begin(),ans.end());
                break;
            }else if(arr[l].first+arr[r].first>target){
                r--;
            }else{
                l++;
            }
        }
        return ans;
    }
};
