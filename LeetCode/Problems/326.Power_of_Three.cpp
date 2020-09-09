class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        double _ten = log10(n);
        double _three = log10(3);
        double ans = _ten/_three;
        if(ans-(int)ans==0){
            return true;
        }
        return false;
    }
};
