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
#include <string.h>
#include <math.h>
#include <string>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void generatePrimes(){

}
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
vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
void solve(){
		ll n,k;
		cin>>n>>k;

		vector<string> board(n);
		for(int i=0;i<n;++i){
			cin>>board[i];
		}
		vector<vector<int> > distnace(n,vector<int>(10));
		for(int i=0;i<n;++i){
			for(int j=0;j<10;++j){
				for(int k=0;k<7;++k){
					if(board[i][k]=='1'&&digits[j][k]=='0'){
						distnace[i][j] = -1;
						break;
					}else if(board[i][k]=='0'&&digits[j][k]=='1'){
						distnace[i][j]++;
					}
				}
			}
		}

		vector<vector<int> > dp(n+1,vector<int>(k+1));
		dp[n][0] = 1;

		for(int i=n;i>0;i--){
			for(int j=0;j<=k;j++){
				if(dp[i][j]){
					for(int d=0;d<10;++d){
						if(distnace[i-1][d]!=-1&&j+distnace[i-1][d]<=k){
							dp[i-1][j+distnace[i-1][d]] = 1;
						}
					}
				}
			}
		}
    //first digit can't be changed with k turnons.
    if(dp[0][k]==0){
      //cout<<"p"<<endl;
      cout<<-1<<'\n';
      return;
    }
		for(int i=0;i<n;++i){
			int now = -1;
			for(int d=9;d>=0;d--){
				if(distnace[i][d]!=-1&&k>=distnace[i][d]&&dp[i+1][k-distnace[i][d]]){
					now = d;
					k = k-distnace[i][d];
					break;
				}
			}
			if(now!=-1){
				cout<<now;
			}else{
			    //cout<<"Q";
				cout<<-1<<endl;
				return;
			}
		}
		cout<<endl;
}
int main(){
		speed;
		solve();
}
