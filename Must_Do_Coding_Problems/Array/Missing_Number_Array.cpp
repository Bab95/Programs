#include <iostream>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int tmp;
	    int x1 = -1,x2=1;
	    for(int i=0;i<n-1;i++){
	        cin>>tmp;
	        if(i==0){
	            x1 = tmp;
	        }else{
	            x1 = x1^tmp;
	        }
	    }
	    for(int i=2;i<=n;i++){
	        x2 = x2^i;
	    }
	    //cout<<x1<<" "<<x2<<endl;
	    int res = x1^x2;
	    cout<<res<<endl;
	}
	return 0;
}
