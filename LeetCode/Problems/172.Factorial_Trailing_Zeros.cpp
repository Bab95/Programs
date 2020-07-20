class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int i = 1;
        while(1){
            int current = n/pow(5,i);
            if(current==0){
                break;
            }
            ans+=current;
            ++i;
        }
        return ans;
    }
};
