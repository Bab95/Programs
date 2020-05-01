// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int binarySearch(int start,int end){
        if(start>end){
            cout<<start<<" "<<end<<endl;
            return -1;
        }
        if(start==end){
            if(isBadVersion(start)){
                return start;
            }
        }
        int mid = start+(end-start)/2;
        if(isBadVersion(mid)){
            if(mid>1&&!isBadVersion(mid-1)){
                return mid;
            }else if(mid==1){
                return mid;
            }else{
                return binarySearch(start,mid-1);
            }
        }else{
            return binarySearch(mid+1,end);
        }
        return -1;
    }
    int firstBadVersion(int n) {
        int ans = binarySearch(1,n);
        return ans;
    }
};
