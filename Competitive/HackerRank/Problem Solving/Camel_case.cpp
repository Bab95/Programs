#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	string s;
	cin>>s;
	int res = 1;
	for(int i=1;i<s.length();i++){
		int tmp = (int)s[i];
		if(tmp>=65&&tmp<=91){
			res++;
		}
	}
	cout<<res<<endl;
}
