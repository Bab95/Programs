class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0){
            return 0;
        }
        long int current = 0;
        for(long int i=1;;++i){
            current+=i;
            if(current>n){
                return i-1;
            }else if(current==n){
                return i;
            }
        }
        return 0;
    }
};
