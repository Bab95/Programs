#include <iostream>
#include <string.h>
using namespace std;
int arr[101];
int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(arr,0,sizeof(arr));
		int min=10001,sum=0,result=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]<min){
				min = arr[i];
			}
			sum+=arr[i];
		}
		result = sum-(n*min);
		cout<<result<<endl;
	}
}
