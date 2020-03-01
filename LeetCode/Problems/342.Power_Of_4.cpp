class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        int x = log2(n);
        return (x==log2(n))&&(x%2==0);
    }
};
