class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long int result = 0;
        int tmp = x;
        while(x){
            int rem = x%10;
            result = result*10+rem;
            x = x/10;
        }
        if(tmp==result){
            return true;
        }
        return false;
    }
};
