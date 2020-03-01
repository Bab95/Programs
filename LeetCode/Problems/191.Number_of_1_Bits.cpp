class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hamming_weight = 0;
        while(n){
            if((n|n<<1)%2==1){
                hamming_weight++;
            }
            n = n>>1;
        }
        return hamming_weight;
    }
};
