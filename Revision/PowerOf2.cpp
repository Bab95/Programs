#include <iostream>
using namespace std;
bool powerof2(unsigned long long int n){
    unsigned long long int  i = n-1;
    return n&&!(i&n);
}
int main() {
	//code
	int t;
	unsigned long long int n;
	cin>>t;
	while(t--){
	    cin>>n;
	    if(powerof2(n)){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
