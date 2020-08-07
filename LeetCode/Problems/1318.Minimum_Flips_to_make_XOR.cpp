class Solution {
public:
    int minFlips(int a, int b, int c) {
        int mask = 1<<30;
        //find first different bit.....
        int t = a | b;
        cout<<t<<endl;
        int ans = 0;
        for(int i=0;i<31;++i){
            if(t&mask==t&c){
                mask = mask>>1;
                continue;
            }else if(t&mask&&!(c&mask)){
                if(a&mask){
                    ans++;
                }
                if(b&mask){
                    ans++;
                }
            }else if(!(t&mask)&&(c&mask)){
                ans++;
            }
            mask = mask>>1;
        }
        return  ans;
    }
};

/*
c[i]=0 _ab[i] = 1

c[i]=1  _ab[i] = 0


1 1 0

1 0 1
*/
