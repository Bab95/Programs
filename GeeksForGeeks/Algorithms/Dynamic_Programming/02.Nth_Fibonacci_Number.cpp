#include <iostream>
#define M 1000000007
typedef unsigned long long int ulli;
using namespace std;
int main() {
	//code
	ulli t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    ulli c,a,b;
	    a = 0;
	    b=1;
	    if(n==0){
	        cout<<a<<endl;
	        continue;
	    }else if(n==1){
	        cout<<b<<endl;
	    }else{
	        for(int i=2;i<=n;i++){
	            c = a%M+b%M;
	            a = b;
	            b = c;
	        }
	        cout<<c%M<<endl;
	    }
	}
	return 0;
}
