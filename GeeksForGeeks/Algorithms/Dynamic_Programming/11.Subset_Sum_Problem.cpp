#include <iostream>
using namespace std;
#define MAX_SIZE 100001
//bool dp[MAX_SIZE][101];
typedef unsigned long long int ulli;
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    ulli sum = 0;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    if(sum%2!=0){
	        cout<<"NO"<<endl;
	    }else{
	        ulli N = sum/2;
	        bool dp[1+N][n+1];
	        for(ulli i=0;i<=N;i++){
	            dp[i][0] = false;
	        }
	        for(int i=0;i<=n;i++){
	            dp[0][i] = true;
	        }
	        for(ulli i=1;i<=N;i++){
	            for(int j=1;j<=n;j++){
	                bool include = (i>=arr[j-1])?dp[i-arr[j-1]][j-1]:dp[i][j-1];
	                bool exclude = dp[i][j-1];
	                dp[i][j] = include||exclude;
	            }
	        }
	        if(dp[N][n]==true){
	            cout<<"YES"<<endl;
	        }else{
	            cout<<"NO"<<endl;
	        }
	    }
	}
	return 0;
}
