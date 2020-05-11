class Solution {
public:
    bool binarySearch(int left,int right,int num){
        if(left>right){
            return false;
        }
        int mid = left + (right-left)/2;
        if(num%mid==0&&(num/mid==mid)){
            return true;
        }else if((num/mid>mid)){
            return binarySearch(mid+1,right,num);
        }else{
            return binarySearch(left,mid-1,num);
        }
        return false;
    }
    bool isPerfectSquare(int num) {
        return binarySearch(1,num,num);
    }
};
