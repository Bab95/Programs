class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low = 0;
        int high = nums1.size();
        while(low<=high){
            int Mid = (nums1.size() + nums2.size() + 1)/2;
            int mid1 = (low+high)/2;
            int mid2 = Mid - mid1;
            int max_left_1 = (mid1==0)?INT_MIN:nums1[mid1-1];
            int max_left_2 = (mid2==0)?INT_MIN:nums2[mid2-1];
            int min_right_1 = (mid1==nums1.size())?INT_MAX:nums1[mid1];
            int min_right_2 = (mid2==nums2.size())?INT_MAX:nums2[mid2];
            if(max_left_1<=min_right_2&&max_left_2<=min_right_1){
                //found the median....
                double ans = 0;
                if((nums1.size()+nums2.size())%2==0){
                    int left = max(max_left_1,max_left_2);
                    int right = min(min_right_1,min_right_2);
                    ans = ((double)left+(double)right)/(1.0*2);
                }else{
                    ans = (double)max(max_left_1,max_left_2);
                }
                return ans;
            }else if(max_left_1>min_right_2){
                high = mid1 - 1;
            }else if(min_right_1<max_left_2){
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};
