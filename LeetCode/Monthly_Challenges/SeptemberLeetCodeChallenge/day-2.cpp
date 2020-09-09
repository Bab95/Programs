class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> window;
        deque<long> current_elements;
        for(int i=0;i<nums.size();++i){
            if(window.size()>k){
                int tmp = current_elements.front();
                window.erase(window.find((long)tmp));
                current_elements.pop_front();
            }
            long low = (long)nums[i] - (long)t;
            long high = (long)nums[i] + (long)t;
            auto it = window.lower_bound(low);
            if(it==window.end()||*it>high){
                window.insert((long)nums[i]);
                current_elements.push_back(nums[i]);
            }else{
                return true;
            }
        }
        return false;
    }
};
