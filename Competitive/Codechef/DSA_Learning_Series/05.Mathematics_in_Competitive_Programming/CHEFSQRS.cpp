#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef int64_t bigint;
void solve(){
    bigint n;
    cin>>n;
    bigint min_square = INT_MAX;
    for(int i=1;i<=sqrt(n);++i){
        if(n%i==0){
            if(n/i==i){
                continue;
            }else{
                bigint f1 = (bigint)max((int)n/i,i);
                bigint f2 = (bigint)min((int)n/i,i);
                if((f1+f2)%2!=0){
                    continue;
                }else{
                    bigint b = (f1+f2)/2;
                    bigint a = (f1-f2)/2;
                    if(a<min_square){
                        min_square = a;
                    }
                }
            }
        }
    }
    if(min_square==INT_MAX){
        cout<<-1<<endl;
        return;
    }
    bigint ans = min_square*min_square;
    cout<<ans<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
