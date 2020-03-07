#include <iostream>
#include <deque>
using namespace std;

int main() {
	//code
	int t,n,k;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int i=0;
	    deque<int> q(k);
	    for(i=0;i<k;i++){
	        while((!q.empty())&&(arr[i]>=arr[q.back()])){
	            q.pop_back();
	        }
	        q.push_back(i);
	    }
	    for(;i<n;i++){
	        cout<<arr[q.front()]<<" ";
	        while((!q.empty())&&(q.front()<=i-k)){
	            q.pop_front();
	        }
	        while((!q.empty())&&(arr[i]>=arr[q.back()])){
	            q.pop_back();
	        }
	        q.push_back(i);
	    }
	    cout<<arr[q.front()];
	    cout<<endl;
	}
	return 0;
}
