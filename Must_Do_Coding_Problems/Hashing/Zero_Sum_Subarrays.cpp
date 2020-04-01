#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    int result = 0;
	    input(arr,n);
	    int sum = 0;
	    unordered_map<int,int> map;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        if(sum==0){
	            result++;
	        }
	        if(map.find(sum)!=map.end()){
	            result += map[sum];
	        }
	        map[sum]++;
	    }
	    cout<<result<<endl;
	}
	return 0;
}
