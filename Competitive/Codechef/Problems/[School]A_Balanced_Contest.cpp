#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int t,n,p;
	cin>>t;
	while(t--){
		cin>>n>>p;
		int hard=0,cake=0;
		//bool fh=true,fc=true;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n;i++){
			if(arr[i]>=p/2){
				cake++;
				if(cake>1){
					//fc = false;
					break;
				}
			}
			else if(arr[i]<=p/10){
				hard++;
				if(hard>2){
					//fh = false;
					break;
				}
			}
		}
		if(cake==1&&hard==2){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
}
