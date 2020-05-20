class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0||nums2.size()==0){
            return {};
        }
        unordered_map<int,int> mmap1;
        unordered_map<int,int> mmap2;
        for(int i=0;i<nums1.size();++i){
            mmap1[nums1[i]]++;
        }
        for(int j=0;j<nums2.size();++j){
            mmap2[nums2[j]]++;
        }
        vector<int> result;
        for(auto it=mmap1.begin();it!=mmap1.end();++it){
            if(mmap2.count(it->first)!=0){
                result.push_back(it->first);
            }
        }
        return result;
    }
};
