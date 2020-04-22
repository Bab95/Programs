class Solution {
public:
    double avg(int a,int b){
        double ans = ((double)a+(double)b)/2.0;
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int x = nums1.size();
        int y = nums2.size();
        int low = 0;
        int high = x;
        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = (x+1+y)/2-mid1;
            int max_left_x = (mid1==0)?INT_MIN:nums1[mid1-1];
            int min_right_x = (mid1==x)?INT_MAX:nums1[mid1];
            int max_left_y = (mid2==0)?INT_MIN:nums2[mid2-1];
            int min_right_y = (mid2==y)?INT_MAX:nums2[mid2];

            if(max_left_x<=min_right_y&&max_left_y<=min_right_x){
                //found.....
                if((x+y)%2==0){
                    return avg(min(min_right_x,min_right_y),max(max_left_x,max_left_y));
                }else{
                    return (double)max(max_left_x,max_left_y);
                }
            }else if(max_left_x>min_right_y){
                high = mid1-1;
            }else{
                low = mid1+1;
            }
        }
        return -1;
    }
};
