#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll sum(int a,int l,int n){
    ll _sum = 0;
    _sum = (ll)n*(ll)(a+l);
    _sum = _sum/2;
    return _sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        n--;
        int _t3 = n/3;
        int _t5 = n/5;
        int _t15 = n/15;
        int l3 = n-(n%3);
        int l5 = n-(n%5);
        int l15 = n-(n%15);
        ll ans = sum(3,l3,_t3) + sum(5,l5,_t5) - sum(15,l15,_t15);
        printf("%lld\n",ans);
        //cout<<_t3<<" "<<_t5<<" "<<_t15<<" "<<l3<<" "<<l5<<" "<<l15<<endl;
    }
    return 0;
}
