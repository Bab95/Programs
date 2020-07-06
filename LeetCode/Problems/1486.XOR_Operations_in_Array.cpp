class Solution {
public:
    int xorOperation(int n, int start) {
        int xo = start;
        for(int i=1;i<n;++i){
            xo ^= (start+2*i);
        }
        return xo;
    }
};
