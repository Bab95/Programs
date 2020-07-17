#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    /*
    vector<int> primes(201,true);
    for(int i=2;i<=sqrt(200);++i){
        if(primes[i]){
            for(int j=i*i;j<=200;j+=i){
                primes[j] = false;
            }
        }
    }
    vector<int> prime;
    for(int i=2;i<=200;++i){
        if(primes[i]){
            prime.push_back(i);
        }
    }
    for(int i=0;i<prime.size();++i){
        cout<<prime[i]<<",";
    }*/
    vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
    unordered_set<int> semi_primes;
    for(int i=0;i<prime.size()-1;++i){
        for(int j=i+1;j<prime.size();++j){
            semi_primes.insert(prime[i]*prime[j]);
        }
    }
    /*for(auto it : semi_primes){
        cout<<it<< " ";
    }
    cout<<endl;*/
    for(auto it : semi_primes){
        int a = it;
        if(semi_primes.count(n-a)!=0){
            //cout<<a<<" "<<n-a<<endl;
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
