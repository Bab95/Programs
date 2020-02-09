#include <iostream>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    int com_sum[n+1];
	    com_sum[0] = 0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        com_sum[i+1] = com_sum[i]+arr[i];
	    }
	    if(n==1){
	        cout<<"1"<<endl;
	        continue;
	    }
	    /*for(int i=0;i<=n;i++){
	        cout<<com_sum[i]<<" ";
	    }
	    cout<<endl;*/
	    bool found = false;
	    for(int i=0;i<n;i++){
	        if(com_sum[i]==com_sum[n]-com_sum[i+1]){
	            int res = i+1;
	            found = true;
	            cout<<res<<endl;
	            break;
	        }
	    }
	    if(!found){
	        cout<<"-1"<<endl;
	    }


	}
	return 0;
}
