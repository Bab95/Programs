#define M 0.00001
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return (double)1;
        }
        double result = (double)1.0;
        int powersign = 1;
        if(n<0){
            powersign = -1;
        }
        n = abs(n);

        while(n>1){
            if(n%2==1){
            result = result*x;
            --n;
            }
            x = x*x;
            n = n/2;
        }
        result = result*x;
        if(powersign==-1){
            result = (double)1.0/result;
            if(result<M){
                return (double)0;
            }

        }
        return result;
    }
};
