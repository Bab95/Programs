#include <iostream>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int n0=0,n1=0,n2=0;
	    int input;
	    for(int i=0;i<n;i++){
	        cin>>input;
	        if(input==0){
	            n0++;
	        }else if(input==1){
	            n1++;
	        }else{
	            n2++;
	        }
	    }
	    int i = 0;
	    if(n0!=0){
	        for(i=0;i<n0;i++){
	            //arr[i] = 0;
	            cout<<"0 ";
	        }
	    }
	    if(n1!=0){
	        for(i=0;i<n1;i++){
	            //arr[i] = 1;
	            cout<<"1 ";
	        }
	    }
	    if(n2!=0){
	        for(i=0;i<n2;i++){
	            //arr[i] = 2;
	            cout<<"2 ";
	        }
	    }
	    cout<<endl;

	}
	return 0;
}
