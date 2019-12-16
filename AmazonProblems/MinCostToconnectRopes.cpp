#include <iostream>
#include <queue>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    priority_queue<int,vector<int>,greater<int> > pq;
	    for(int i=0;i<n;i++){
	        cin>>arr[n];
	        pq.push(arr[n]);
	    }
	    unsigned long long int result = 0;
	    for(int i=0;i<n-1;i++){
	        int a = pq.top();
	        pq.pop();
	        int b = pq.top();
	        pq.pop();
	        result+=(a+b);
	        pq.push(a+b);
	    }
	    cout<<result<<endl;
	}
	return 0;
}
