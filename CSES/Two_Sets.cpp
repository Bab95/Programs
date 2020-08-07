/*
  *author: Captain_Levi*

*/
#define _CRT_SECURE_NO_WARNINGS

typedef __int128_t bint;
#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
template <typename T>
void input_vector(vector<T>& arr){
  for(int i=0;i<arr.size();++i){
    cin>>arr[i];
  }
}
template <typename T>
void print(vector<T>& arr){
  for(int i=0;i<arr.size();++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
void print_set(unordered_set<ll>& ss){
	cout<<ss.size()<<endl;
	//ll sum = 0;
	for(auto it : ss){
		cout<<it<<" ";
		//sum += it;
	}
	//cout<<"sum: "<<sum<<endl;
	cout<<endl;
}
void solve_even(ll n){
	ll sum = 0;
  if(n%2==0){
    sum = n/2;
    sum *= (n+1);
  }else{
    sum = (n+1)/2;
    sum *= n;
  }
	if(sum%2==1){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		unordered_set<ll> ss;
		for(int i=1;i<=n;++i){
			ss.insert(i);
		}
		unordered_set<ll> first;
		ll rem = sum/2;
		ll current = 0;
		int i = 1;
		while(true){
			if(rem==0){
        		print_set(first);
				print_set(ss);
				return;
			}
			if(ss.count(rem)!=0){
				first.insert(rem);
				ss.erase(rem);
				print_set(first);
				print_set(ss);
        return;
			}else{
				if(i>rem){
					//bad case....
					int _bad = i-rem;
					if(first.count(_bad)!=0){
						first.erase(_bad);
						ss.insert(_bad);
						rem += _bad;
					}
				}
				rem -= i;
				first.insert(i);
				ss.erase(i);
				++i;
			}
		}
	}
}

void solve_odd(ll n){
	ll sum = 0;
	if(n%2==0){
		sum = n/2;
		sum *= (n+1);
	}else{
		sum = (n+1)/2;
		sum *= n;
	}
	if(sum%2==1){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		unordered_set<ll> s1,s2;
		ll _s1 = 0,_s2 = 0;
		ll _i1,_i2;
		ll rem = -1;
		_i1 = n/2;
		rem = n/2 + 1;
		_i2 = rem + 1;
		while(_i1>0&&_i2<=n){
			if(_s1<_s2){
				_s1 += _i2;
				_s2 += _i1;
				s1.insert(_i2);
				s2.insert(_i1);
				_i2++;
				_i1--;
			}else{
				_s1 += _i1;
				_s2 += _i2;
				s1.insert(_i1);
				s2.insert(_i2);
				_i1--;
				_i2++;
			}
		}
		if(rem!=-1){
			if(_s1<_s2){
				s1.insert(rem);
			}else{
				s2.insert(rem);
			}
		}
		print_set(s1);
		print_set(s2);
	}
}
void solve(){
	ll n;
	cin>>n;
	if(n%2==0){
		solve_even(n);
	}else{
		solve_odd(n);
	}
}
int main(){
  solve();
  //solve_t();
  return 0;
}
