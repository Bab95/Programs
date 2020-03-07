#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	unsigned long long int n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int sum = 0;
	    while(n/10!=0){
	        sum = 0;
	       while(n){
	           int rem = n%10;
	           n = n/10;
	           sum+=rem;
	       }
	       n = (sum==0)?n:sum;
	    }
	    cout<<n<<endl;
	}
	return 0;
}
s
