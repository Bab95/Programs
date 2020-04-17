typedef long long int ll;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<ll> window;
        deque<int> dq;
        for(int i=0;i<nums.size();++i){
            if(window.size()>k){
                int outdated = dq.front();
                window.erase(window.find((ll)outdated));
                dq.pop_front();
            }

            auto it = window.lower_bound((ll)nums[i]-(ll)t);
            if(it==window.end()||*it>(ll)nums[i]+(ll)t){
                //kee going not found...
                window.insert((ll)nums[i]);
                dq.push_back(nums[i]);
            }else{
                //found...
                return true;
            }
        }
        return false;
    }
};
