#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
typedef long long int ll;
#define M 1000001
bool primes[M];
void sieve(){
    //memset(primes,false,sizeof(primes));
    for(int i=2;i*i<=M;i++){
        if(primes[i]==false){
            for(int j=i*i;j<=M;j+=i){
                primes[j] = true;
            }
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    ll sum = 0;
    
    for(int i=2;i<=n;i++){
        if(!primes[i]){
            sum += i;
            //cout<<i<<" ";
        }
    }
    //cout<<endl;
    cout<<sum<<endl;
}
int main() {
	//code
	sieve();
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}