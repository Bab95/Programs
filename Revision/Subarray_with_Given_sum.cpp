#include <iostream>
using namespace std;

int main() {
	//code
	int t,n,sum;
	cin>>t;
	while(t--){
	    cin>>n>>sum;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int current_start = 0;
	    int current_end = 0;
	    int current_sum = arr[0];
	    int found = false;
	    while(current_end<=n-1){
	        if(current_sum==sum){
	            found = true;
	            cout<<current_start+1<<" "<<current_end+1<<endl;
	            break;
	        }else if(current_sum>sum){
	            current_sum = current_sum-arr[current_start];
	            current_start++;
	        }else{
	            current_sum = current_sum+arr[++current_end];
	            if(current_end>=n){
	                //found = false;
	                break;
	            }
	        }

	    }
	    if(!found){
	        cout<<"-1"<<endl;
	    }

	}
	return 0;
}
