#include <bits/stdc++.h>
using namespace std;
int getbits(int a){
    int count = 0;
    while(a){
        count += a&1;
        a>>=1;
    }
    return count;
}
int findNumber(int n,int s){
    int x = pow(2,n)-1;
    int y = pow(2,n-s)-1;
    return x^y;
}
int solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int bitsa = getbits(a);
    int bitsb = getbits(b);
    int ans = 0;
    int setbits;
    if(bitsa+bitsb<=n){
        setbits = bitsa+bitsb;
    }else{
        int over = bitsa + bitsb - n;
        setbits = n - over;
    }
    ans = findNumber(n,setbits);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}
