class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mmap;
        stack<int> stk;
        stk.push(-1);
        for (int i=nums2.size()-1;i>=0;i--){
            while (!stk.empty() && stk.top() < nums2[i]){
                stk.pop();
            }
            if (stk.empty()) {
                mmap[nums2[i]] = -1;
            }else{
                mmap[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
        }
        for (int i=0;i<nums1.size();i++){
            nums1[i] = mmap[nums1[i]];
        }
        return nums1;
    }
};
