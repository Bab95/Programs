class Solution {
public:
    bool isArmstrong(int N) {
        int ans = 0;
        int x = N;
        int k = 0;
        while(N){
            N /= 10;
            k++;
        }
        N = x;
        while(N){
            int rem = N%10;
            ans += pow(rem,k);
            N = N/10;
        }
        if(ans==x){
            return true;
        }
        return false;
    }
};
