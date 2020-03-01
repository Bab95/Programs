class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0;i<32;i++){
            int tmp = ((n|n<<1)%2==0)?0:1;
            result += tmp*pow(2,31-i);
            n = n>>1;
        }
        return result;
    }
};
