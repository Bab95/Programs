#include <iostream>
using namespace std;
bool isPaying(int arr[],int n,int m){
	if(m==0){
		return true;
	}
	if(m!=0&&n==0){
		return false;
	}
	if(arr[n-1]>m){
		return isPaying(arr, n-1,m);
	}
	return isPaying(arr,n-1,m)||isPaying(arr,n-1,m-arr[n-1]);
}
int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;
		cin>>m;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		if(isPaying(arr,n,m)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
