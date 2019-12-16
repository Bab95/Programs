class Solution {
public:
    double avg(int a,int b){
        double result = (double)((double)a+(double)b)/2;
        return result;
    }
    int min(int a,int b){
        return a<b?a:b;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low = 0;
        int high = n;
        while(low<=high){
            int partitionX = (low+high)/2;
            int partitionY = (n+m+1)/2-partitionX;
            int max_left_X = (partitionX==0)?INT_MIN:nums1[partitionX-1];
            int max_left_Y = (partitionY==0)?INT_MIN:nums2[partitionY-1];
            int min_right_X = (partitionX==n)?INT_MAX:nums1[partitionX];
            int min_right_Y = (partitionY==m)?INT_MAX:nums2[partitionY];
            if(max_left_X<=min_right_Y&&max_left_Y<=min_right_X){
                if((n+m)%2==0){
                    double median = avg(max(max_left_X,max_left_Y),min(min_right_X,min_right_Y));
                    return median;
                }else{
                    double median = (double)max(max_left_X,max_left_Y);
                    return median;
                }
            }
            else if(max_left_X>min_right_Y){
                high = partitionX-1;
            }else{
                low = partitionX+1;
            }
        }
        return -1;
    }
};
