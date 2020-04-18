#include <iostream>
using namespace std;
int main(){
	long long int n;
	cin>>n;
	long long int sum = 0;
	long long int input;
	for(long long int i=0;i<n;i++){
		cin>>input;
		sum+=input;
		sum-=(i+1);
	}
	if(sum==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}
