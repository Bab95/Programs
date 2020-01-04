#include <iostream>
using namespace std;
typedef unsigned long long int ulli;
#define M 1000000007
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    ulli dp[n+1];
	    dp[0] = 0;
	    dp[1] = 1;
	    dp[2] = 2;
	    for(int i=3;i<=n;i++){
	        dp[i] = dp[i-1]%M+(i-1)*dp[i-2]%M;
	        dp[i] = dp[i]%M;
	    }
	    cout<<dp[n]%M<<endl;
	}
	return 0;
}
