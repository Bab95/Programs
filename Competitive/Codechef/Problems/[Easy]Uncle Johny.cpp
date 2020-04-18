#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int uj;
		cin>>uj;
		int luj = arr[uj-1];
		sort(arr, arr+n);
		int res = 0;
		for(int i=0;i<n;i++){
			if(arr[i]<luj){
				res++;
			}else if(arr[i]==luj){
				break;
			}
		}
		cout<<res+1<<endl;

	}
}
