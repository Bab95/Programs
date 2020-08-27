#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int zeros = 0;
	int ones = 0;
	for(int i=0;i<s.length();++i){
		if(s[i]=='1'){
			ones++;
		}else{
			zeros++;
		}
	}
	int mul = n/k;
	if(ones!=0&&ones<mul){
	    cout<<"IMPOSSIBLE"<<endl;
	    return;
	}else if(zeros!=0&&zeros<mul){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}else if(ones%mul!=0||zeros%mul!=0){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	//vector<char> ans(s.lenght());
	string a;
	int count = 0;
	for(int i=0;i<zeros/mul;++i){
		a.push_back('0');
	}
	for(int i=0;i<ones/mul;++i){
		a.push_back('1');
	}
	string b;
	for(int i=a.length()-1;i>=0;i--){
		b.push_back(a[i]);
	}
	string ans = "";
	int len = 0;
	while(len<s.length()){
		ans = ans.append(a);
		len = len + a.length();
		if(len==s.length()){
			break;
		}
		ans = ans.append(b);
		len = len + b.length();
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
