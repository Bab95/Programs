#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#include <stack>
#include <string.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
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
void input(vector<ll>& arr,int n){
	fo(i,0,n-1){
		cin>>arr[i];
	}
}
void input(vector<ulli>& arr,int n){
		fo(i,0,n-1){
				cin>>arr[i];
		}
}
ll max(ll a,ll b){
		return a>b?a:b;
}
ulli max(ulli a,ulli b){
		return a>b?a:b;
}
int max(int a,int b){
		return a>b?a:b;
}
void print(vector<int>& ans,int n){
		fo(i,0,n-1){
				cout<<ans[i]<<" ";
		}
		cout<<endl;
}
void print(vector<ll>& ans,int n){
		fo(i,0,n-1){
				cout<<ans[i]<<" ";
		}
		cout<<endl;
}
int solve(){
		int n;
		cin>>n;
		vector<int> arr(n);
		unordered_map<int,int> mmap;
		input(arr,n);
		//test1..primes
		/*int prime_count = 0;
		int prime_index = 0;
		int non_prime_index = 0;
		fo(i,0,n-1){
			if(isprime[arr[i]]){
				prime_count++;
				prime_index = i;
			}else{
				non_prime_index = i;
			}
		}
		if(prime_count==1||prime_count==n-1){
			//ans fount...
			if(prime_count==1){
				return prime_index;
			}

			if(prime_count==n-1){
				return non_prime_index;
			}
		}*/
		//
		int even_count = 0;
		int even_index = 0;
		int odd_index = 0;
		fo(i,0,n-1){
			if(arr[i]%2==0){
				even_count++;
				even_index = i;
			}else{
				odd_index = i;
			}
		}
		if(even_count==1||even_count==n-1){
			if(even_count==1){
				return even_index;
			}
			if(even_count==n-1){
				return odd_index;
			}
		}
		return -1;
}
bool* generatePrimes(){
	bool* isprime = new bool[101];
	memset(isprime,true,sizeof(bool)*101);
	for(int i=2;i*i<=100;i++){
		if(isprime[i]==true){
			for(int j=i*i;j<=100;j+=i){
				isprime[j] = false;
			}
		}
	}
	return isprime;
}
int main(){
		speed;
		bool* isprime = generatePrimes();
		cout<<solve()+1<<endl;
}
