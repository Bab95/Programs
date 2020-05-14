#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#include <stack>
#include <math.h>
#include <string>
#define M 1000000000
bitset<M> primes(0);
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
using namespace std;

vector<int> Prime_numbers;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void input(vector<int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
void print(vector<int>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
bool solve(){
    long long int n,k;
    cin>>n>>k;
    vector<int> PowersPrimes(k,0);
    int i = 2;
    
    while(true){
        int tmp = i;
        int total = 1;
        int j = 0;
        for(int k = Prime_numbers[j];k*k<=tmp;k=Prime_numbers[++j]){
            int count = 0;
            while(tmp%k==0){
                ++count;
                tmp = tmp/k;
            }
            total = (total)*(count+1);
        }
        if(tmp!=1){
            total = total*2;
        }
        if(total==n){
            return true;
        }
        ++i;
    }
    return false;
}
void generatePrime(){
    primes[1] = 1;
    for(int i=2;i*i<M;++i){
        Prime_numbers.pb(i);
        if(primes[i]==0){
            for(int j=i*i;j<=M;j+=i){
                primes[j] = 1; 
            }
        }
    }
}
int main(){
    int t;
    generatePrime();
    cin>>t;
    while(t--){
        solve();
    }
}