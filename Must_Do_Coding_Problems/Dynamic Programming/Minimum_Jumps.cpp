#include <iostream>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    if(arr[0]==0){
	        cout<<-1<<endl;
	        continue;
	    }
	    int current_position = arr[0];
	    int max_reach = arr[0];
	    int jumps = 1;
	    for(int i=1;i<n;i++){

	        if(current_position==i&&max_reach==i&&arr[i]==0){
	            jumps = -1;
	            break;
	        }
	        if(current_position<i){
	            current_position = max_reach;
	            jumps++;
	        }
	        max_reach = max(max_reach,i+arr[i]);
	    }
	    cout<<jumps<<endl;
	}
	return 0;
}
