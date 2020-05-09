#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
void solve() {
	//code
    ll n;
	cin>>n;
	vector<bool> primes(n+1,false);
    for(int i=2;i*i<=n;i++){
        if(primes[i]==false){
            for(int j=i*i;j<=n;j+=i){
                primes[j] = true; 
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(primes[i]==false){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}