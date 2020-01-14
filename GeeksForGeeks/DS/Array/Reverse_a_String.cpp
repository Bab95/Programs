#include <iostream>
#include <string>
using namespace std;
void swap(char *a,char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int main() {
	//code
	int t;
	string s;
	cin>>t;
	while(t--){
	    cin>>s;
	    int l = 0;
	    int r = s.length()-1;
	    while(l<r){
	       swap(&s[l],&s[r]);
	       l++;
	       r--;
	    }
	    cout<<s<<endl;
	}
	return 0;
}
