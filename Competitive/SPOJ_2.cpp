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
#define fo(i,l,r) for(long long int i=l;i<=r;++i)
#define fi(i,r,l) for(long long int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define M 100000000
using namespace std;
bitset<M> prime;
void generate(){
    prime[1] = 1;
	for(int i=2;i*i<M;++i){
		if(prime[i]==0){
			for(int j=i*i;j<M;j+=i){
				prime[j] = 1;
			}
		}
	}
}
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void input(vector<long long int>& arr,long long int n){
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
void solve(){
    long long int m,n;
    cin>>m>>n;
    fo(i,m,n){
    	if(prime[i]==0){
    		cout<<i<<endl;
    	}
    }
    //cout<<endl;
    //vector<long long int> arr(n);
    //input(arr,n);
}
int main(){
    int t;
    generate();
    cin>>t;
    while(t--){
        solve();
    }
}