#include <iostream>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    int sum = 0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    if(sum%2!=0){
	        cout<<"NO"<<endl;
	    }else{
	        sum = sum/2;
	        bool dp[n+1][sum+1];
	        for(int i=1;i<=n;i++){
	            dp[i][0] = true;
	        }
	        for(int i=0;i<=sum;i++){
	            dp[0][i] = false;
	        }
	        for(int i=1;i<=n;i++){
	            for(int j=1;j<=sum;j++){
	                if(j>=arr[i-1]){
	                    bool include = dp[i][j-arr[i-1]];
	                    bool exclude = dp[i-1][j];
	                    dp[i][j] = include||exclude;
	                }else{
	                    dp[i][j] = dp[i-1][j];
	                }
	            }
	        }
	        if(dp[n][sum]){
	            cout<<"YES"<<endl;
	        }else{
	            cout<<"NO"<<endl;
	        }
	    }

	}
	return 0;
}
