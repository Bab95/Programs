#include <iostream>
#include <math.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	unsigned long long int n;
	while(t--){
	    cin>>n;
	    int power = log2(n);
	    unsigned long long int ans = (unsigned long long int)pow(2,power);
	    cout<<ans<<endl;
	}
	return 0;
}
