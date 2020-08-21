#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
const int MAX = 1e5+5;
using namespace std;
int primes[MAX];
//vector<vector<pair<int,int> > > prime_factors(MAX,vector<pair<int,int> >());
vector<pair<int,int> > prime_factors[MAX];
int prefix[MAX][6];
int A[MAX];
void sieve(){
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
        int x = i;
        map<int,int> mmap;
        while(x!=1){
            mmap[primes[x]]++;
            x /= primes[x];
        }
        for(auto p : mmap){
            prime_factors[i].push_back(p);
        }
    }
    for(int i=1;i<MAX;++i){
        A[i] = prime_factors[i].size();
    }
    for(int i=1;i<MAX;++i){
        for(int k=1;k<=5;++k){
            prefix[i][k] = prefix[i-1][k] + (A[i]==k);
        }
    }
}
void solve(){
    int a,b,k;
    cin>>a>>b>>k;
    cout<<prefix[b][k]-prefix[a-1][k]<<endl;
}
int main() {
	int t;
	speed;
	sieve();
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
