#include <bits/stdc++.h>
using namespace std;
long long getSum(int [],int n);
main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];

		cout<<getSum(a,n)<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
#define M 1000000007
int fact(int n){
    int result = 1;
    for(int i=2;i<=n;i++){
        result = result*i;
    }
    return result;
}
long long power(int n,int q){
    long long result = 1;
    for(int i=0;i<n;i++){
        result = result*q;
    }
    return result;
}
long long getSum(int arr[],int n)
{
    //Your code here
    long long int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int f = fact(n);
    f = f/n;
    long long tmp = f*sum;
    long long result = 0;
    for(int i=0;i<n;i++){
        result+=tmp*power(i,10);
    }
    return result%M;

}
