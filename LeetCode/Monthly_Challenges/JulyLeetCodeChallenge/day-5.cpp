class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int m = 1;
        for(int i=0;i<31;++i){
            int a = x&m;
            int b = y&m;
            if(a!=b){
                count++;
            }
            m = m<<1;
            //x = x >> 1;
            //y = y >> 1;
            //cout<<"a: "<<a<<" b: "<<b<<" m: ";
            cout<<m<<endl;
        }
        return count;
    }
};
