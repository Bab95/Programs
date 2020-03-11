#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<int> BigInt;
typedef long long int ll;
typedef int64_t ll;
#define pb push_back
#define FORI(i,l,r) for(int i=l;i<=r;i++)
#define FORD(i,r,l) for(int i=r;i>=l;i--)
void Set(BigInt &a){
	while(a.size()>1&&a.back()==0){
		a.pop_back();
	}
}
BigInt Integer(string s){
	BigInt ans;
	if(s[0]=='-'){
		return ans;
	}
	if(s.size()==0){
		ans.pb(0);
		return ans;
	}
	while(s.size()%9!=0){
		s = '0'+s;
	}
	cout<<"before converting "<<s<<endl;
	for(int i=0;i<s.size();i+=9){
		int v = 0;
		for(int j=i;j<i+9;j++){
			v = v*10+(s[j]-'0');
		}
		cout<<"v:"<<v<<endl;
		ans.insert(ans.begin(),v);
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	Set(ans);
	return ans;
}

BigInt Integer(ll x){
	string s = "";
	while(x>0){
		s = (char)(x%10 +'0') + s;
		x /=10;
	}
	return Integer(s);
}
BigInt Integer(int x){
		return Integer((ll)x);
}
void operator >> (istream &in , BigInt &a){
	string s;
	getline(cin,s);
	a = Integer(s);
}
void Print(BigInt& a){
	Set(a);
	printf("%d",(a.size()==0)?0:a.back());
	FORD(i,a.size()-2,0){
		printf("%09d",a[i]);
	}
	cout<<endl;
}
void operator << (ostream &out, BigInt a){
	Print(a);
}

int main(){
	BigInt A = Integer("123747589578978957857850785578578578978952578785957878954798549782");
	cout<<A;
}
