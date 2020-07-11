class Solution {
public:
    bool sign(int x){
        if(x<0){
            return true;
        }
        return false;
    }
    int reverse(int x) {
        long int ans = 0;
        bool neg = sign(x);
        x = abs(x);
        while(x){
            int rem = x%10;
            x = x/10;
            ans = ans*10+rem;
        }
        if(neg){
            ans = ans*-1;
        }
        if(ans>INT_MAX||ans<INT_MIN){
            return 0;
        }
        return ans;
    }
};
