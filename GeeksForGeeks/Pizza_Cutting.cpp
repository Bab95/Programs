/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
typedef int64_t ii;
int main(){
	int t;
	cin>>t;
	while(t--){
		ii n;
		cin>>n;
		ii ans = 0;
		if(n==0){
			ans=1;
		}else{
			if(n%2==0){
				ans = n/2;
				ans = ans*(n+1);
			}else{
				ans = n+1;
				ans = ans/2;
				ans = ans*n;
			}
			ans+=1;
		}
		cout<<ans<<endl;
	}
}
