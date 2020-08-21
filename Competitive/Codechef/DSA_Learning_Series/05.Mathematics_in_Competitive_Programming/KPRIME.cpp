#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
const int MAX = 1e5+5;

using namespace std;
std::vector<std::unordered_set<int> > prime_factors(MAX,std::unordered_set<int>());
int primes[MAX];
int prefix[MAX][6];
void sieve(){
    //primes i stores the largest prime factor of a number....
    for(int i=2;i<MAX;++i){
        if(primes[i]!=0){
            continue;
        }
        primes[i] = i;
        for(int j=2*i;j<MAX;j+=i){
            primes[j] = i;
        }
    }

    for(int i=2;i<MAX;++i){
        int current = i;

        while(current!=1){
            prime_factors[i].insert(primes[current]);
            current = current/primes[current];
        }
    }

    for(int i=1;i<MAX;++i){
        for(int k=1;k<=5;++k){
            prefix[i][k] = prefix[i-1][k] + (prime_factors[i].size()==k);
        }
    }

}
void solve(){
    int a,b,k;
    cin>>a>>b>>k;
    cout<<prefix[b][k]-prefix[a-1][k]<<endl;
    return;
}
int main() {
    sieve();
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
