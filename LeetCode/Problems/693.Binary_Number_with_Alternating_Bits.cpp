class Solution {
public:
    bool hasAlternatingBits(int n) {
        int _bit = n&1;
        n = n>>1;
        while(n){
            int current = n&1;
            if(current==_bit){
                return false;
            }
            _bit = current;
            n = n>>1;
        }
        return true;
    }
};
