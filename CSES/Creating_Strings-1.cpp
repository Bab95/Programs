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
		cout<<arr[i]<<"\n";
	}
	cout<<endl;
}
int factorial(int n){
	if(n==0){
		return 1;
	}
	vector<int> f(n+1,0);
	f[0] = 1;
	f[1] = 1;
	for(int i=2;i<=n;++i){
		f[i] = i*f[i-1];
	}
	return f[n];
}
string next_string(string& s){
	int i = s.length()-1;
	while(i>0&&s[i-1]>=s[i]){
		i--;
	}
	if(i<=0){
		return s;
	}
	int current = i-1;
	int to_swap = i;
	for(int j=i+1;j<s.length();++j){
		if(s[j]>s[current]&&s[j]<s[to_swap]){
			to_swap = j;
		}
	}
	swap(s[current],s[to_swap]);
	sort(s.begin()+i,s.end());
	return s;
}
void solve(){
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	unordered_set<string> found;
	found.insert(s);
	int total = factorial(s.length());
	//cout<<total<<endl;
	vector<string> ans;
	ans.reserve(total);
	ans.push_back(s);
	for(int i=0;i<total;++i){
		s = next_string(s);
		//cout<<"debug: "<<i<<" :"<<s<<endl;
		if(found.find(s)==found.end()){
			ans.push_back(s);
			found.insert(s);
		}
	}
	cout<<ans.size()<<endl;
	print(ans);
}
void solve_t(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
int main(){
	solve();
	//solve_t();
	return 0;
}
