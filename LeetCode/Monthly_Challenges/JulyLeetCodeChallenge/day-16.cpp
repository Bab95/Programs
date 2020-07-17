class Solution {
public:
    double find_power(double x,long int n){
        if(n==0){
            return 1;
        }
        if(n%2==0){
            double a = find_power(x,n/2);
            return a*a;
        }else if(n%2==1){
            double ans;
            n--;
            ans = find_power(x,n/2);
            return ans*ans*x;
        }
        return 1;
    }
    double myPow(double x, int n) {
        bool flag = true;
        long int N = (long int)n;
        if(n<0){
            N = abs(N);
            flag = false;
        }
        double ans = find_power(x,N);
        if(!flag){
            ans = 1/ans;
        }
        return ans;
    }
};
