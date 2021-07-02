/*

Solution: Segmented Sieve
And range is very large it's not possible to make such a big array
But we are sure that range i.e. (b-a) is in range of 1e6.
So normalize the range accordingly.
find prime numbers lesser than sqrt(b)
and then mark all the multiples of these primes in a to b as non primes

*/
#include <bits/stdc++.h>
using namespace std;
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;
typedef unsigned long long int ulli;
const int _size = 1e6 + 5;
vector<int> sieve(){
    bool primes[_size];
    const int MAX_VAL = 1e6+1;
    memset(primes,true,sizeof(primes));
    for(int i=2;i*i<=_size;++i){
        if(primes[i]){
            for(int j=i*i;j<=MAX_VAL;j+=i){
                primes[j] = false;
            }
        }
    }
    vector<int> PrimeNumbers;
    PrimeNumbers.push_back(2);
    for(int i=3;i<=_size;i+=2){
        if(primes[i]){
            PrimeNumbers.push_back(i);
        }
    }
    return PrimeNumbers;
}
int main(){
    int t;
    cin>>t;
    vector<int> Primes = sieve();
    /*
    for(int i=0;i<Primes.size();++i){
        cout<<Primes[i]<<" ";
    }
    cout<<endl;
    */
    while(t--){
        lli a,b;
        cin>>a>>b;
        if(a==1){
            a+=1;
        }
        /*
        if(b<_size){
            for(int i=0;i<Primes.size()&&Primes[i]<=b;i++){
                if(Primes[i]>=a){
                    cout<<Primes[i]<<"\n";
                }
            }
            cout<<"\n";
            continue;
        }*/
        vector<bool> prime_segment(b-a+1,true);
        for(int i=0;(lli)Primes[i]*(lli)Primes[i]<=b;i++){
            lli base_value = (a/Primes[i])*Primes[i];
            if(base_value<a){
                base_value += Primes[i];
            }
            for(lli j= base_value;j<=b;j+=Primes[i]){
                prime_segment[j-a] = false;
            }
            if(base_value == Primes[i]){
                prime_segment[base_value-a] = true;
            }
        }
        for(int i=0;i<=b-a;++i){
            if(prime_segment[i]){
                cout<<i+a<<"\n";
            }
        }
        cout<<"\n";
        
    }
    return 0;
} 