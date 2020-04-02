// { Driver Code Starts
#include <bits/stdc++.h>
# define ll long long int
#define N 10000
using namespace std;

long long int sum_of_XOR(int arr[], int n);

int main()
{
    int arr[N];

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<< sum_of_XOR(arr,n) << endl;
    }
	return 1;
}// } Driver Code Ends
long long int sum_of_XOR(int arr[], int n)
{
    int dp[n];
    //memset(dp,0,sizeof(dp));
    long long int sum = 0;
    for(int i=0;i<n-1;i++){
        dp[i] = arr[i];
        sum += dp[i];
        for(int j=i+1;j<n;j++){
            dp[j] = dp[j-1] ^ arr[j];
            sum += dp[j];
        }
    }
    sum += arr[n-1];
    return sum;
}
