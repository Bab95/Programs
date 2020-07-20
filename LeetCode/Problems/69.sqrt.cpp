class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int low = 1;
        int high = x/2;
        int ans = 1;
        while(low<=high){
            long int mid = (long int)(low+high)/2;
            if(mid*mid==x){
                return mid;
            }else if(mid*mid<x){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};
