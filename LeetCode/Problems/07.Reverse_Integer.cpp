#define RANGE_UP 2147483647
#define RANGE_DOWN -2147483648
class Solution {
public:
    int reverse(int data) {
        long long int x = data;
        bool flag = false;
        if(x<0){
            flag = true;
            x = x*-1;
        }
        long long int ans = 0;
        while(x){
            int rem = x%10;
            ans = ans*10+rem;
            x = x/10;
        }
        if(flag){
            ans = ans*-1;
        }
        if(ans>RANGE_UP||ans<RANGE_DOWN){
            return 0;
        }
        return ans;
    }
};
