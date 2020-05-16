#include <iostream>
#include <vector>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
ll min(ll a,ll b){
		return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
void solve(){
		ll n,k;
		cin>>n>>k;
		vector<int> arr(n);
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}
		vector<int> last_visit(k+1,-1);
		int max_length = 0;
		for(int i=0;i<n;++i){
		    max_length = max(max_length,i-last_visit[arr[i]]-1);
        //cout<<"printing-->"<<max_length<<endl;
        last_visit[arr[i]] = i;
		}
    for(int i=1;i<=k;++i){
      max_length = max(max_length,n-last_visit[i]-1);
    }
		cout<<max_length<<endl;
}
int main(){
		speed;
		int t;
		cin>>t;
		while(t--){
				solve();
		}
}
