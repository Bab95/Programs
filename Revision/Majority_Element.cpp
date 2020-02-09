#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	//code
	int t;
	int n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    unordered_map<int,int> my_map;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        my_map[arr[i]]++;
	    }
	    int result = -1;
	    for(auto itr:my_map){
	        if(itr.second>n/2){
	            result = itr.first;
	        }
	    }
	    cout<<result<<endl;

	}
	return 0;
}
