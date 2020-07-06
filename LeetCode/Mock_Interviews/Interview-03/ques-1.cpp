class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int m = 1;
        for(int i=0;i<32;++i){
            int current_bit = (n&m);
            n = n>>1;
            ans = ans<<1;
            ans = ans|current_bit;
        }
        return ans;
    }
};
