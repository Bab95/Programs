#include <iostream>
#include <vector>
using namespace std;

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
	    vector<int> result;
	    result.push_back(arr[n-1]);
	    int max_so_far = arr[n-1];
	    for(int i=n-2;i>=0;i--){
	        if(arr[i]>=max_so_far){
	            max_so_far = arr[i];
	            result.push_back(arr[i]);
	        }
	    }
	    for(int i=result.size()-1;i>=0;i--){
	        cout<<result[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
