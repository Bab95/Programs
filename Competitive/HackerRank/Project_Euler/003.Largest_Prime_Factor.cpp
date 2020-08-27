#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans;
        while(n%2==0){
            n /= 2;
        }
        if(n==1){
            ans = 2;
        }else{
            ll i = 1;
            for(i=3;i<=sqrt(n);i+=2){
                if(n%i==0){
                    n = n/i;
                    i = 1;
                }
            }
            //in case n was a prime from the begining
            if(n>2){
                ans = n;
            }else{
                ans = i;
            }
        }
        printf("%lld\n",ans);

    }
    return 0;
}
/*

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans = -1;
        while(n%2==0){
            n /= 2;
        }
        if(n==1){
            ans = 1;
        }else{
            for(ll i=3;i<=sqrt(n);i+=2){
                while(n%i==0){
                    n = n/i;
                    ans = i;
                }
            }
            if(n>2){
                ans = n;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


*/
