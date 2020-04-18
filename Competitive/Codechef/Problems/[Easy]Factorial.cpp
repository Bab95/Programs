#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	unsigned long long int n,result,x;
	while(t--){
		cin>>n;
		result = 0;
		int i = 1;
		unsigned long long int tmp = 1;
		x = n;
		while(x){
			//tmp = pow(5,i);
			tmp = tmp*5;
			result+=n/tmp;
			x = n/tmp;
			i++;
		}
		cout<<result<<endl;
	}
}
