#include <iostream>
int main() {
	//code
	int t,n;
	cin>>t;
	int sum = 0;
	while(t--){
	    cin>>n;
	    int *arr = new int[n];
	    sum = 0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    if(sum%2!=0){
	        cout<<"NO"<<endl;
	    }else{
	        sum = sum/2;
	        //bool **dp = new bool*[sum+1];
	        bool dp[sum+1][n+1];
	        //for(int i=0;i<=sum;i++){
	          //  dp[i] = new bool[n+1];
	        //}
	        for(int i=0;i<=n;i++){
	            dp[0][i] = true;
	        }
	        for(int j=1;j<=sum;j++){
	            dp[j][0] = false;
	        }
	        for(int i=1;i<=sum;i++){
	            for(int j=1;j<=n;j++){
	                dp[i][j] = dp[i][j-1];
	                if(i>=arr[j-1]){
	                    dp[i][j] = dp[i][j]||dp[i-arr[j-1]][j-1];
	                }
	            }
	        }
	        if(dp[sum][n]){
	            cout<<"YES"<<endl;
	        }else{
	            cout<<"NO"<<endl;
	        }

	    }
	}
	return 0;
}
