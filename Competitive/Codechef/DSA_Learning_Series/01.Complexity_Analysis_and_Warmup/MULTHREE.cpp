#include <iostream>
using namespace std;
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define ll long long int
#define ulli unsigned long long int
void solve(){
	ll k;
	ll di,d0,d1;
	cin>>k>>d0>>d1;
	//ll dis = d0+d1;
	ulli sum = d0+d1;
	ll i = 2;
	for(i=2;i<k;++i){
		di = sum%10;
		if(di==6){
			break;
		}
		sum+=di;
		if(sum%10==0){
			if(sum%3==0){
				cout<<"YES";
			}else{
				cout<<"NO";
			}
			return;
		}
	}
	ll rem = (k-i)%4;
	ll mul = (k-i)/4;
	if(rem==1){
		sum+=6;
	}
	if(rem==2){
		sum+=6;
		sum+=2;
	}
	if(rem==3){
		sum+=6;
		sum+=2;
		sum+=4;
	}
	int tmp = ((20%3)*mul)%3;
	sum+=tmp;
	if(sum%3==0){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}
