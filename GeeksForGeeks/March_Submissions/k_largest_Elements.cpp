#include <iostream>
#include <queue>
using namespace std;

int main() {
	//code
	priority_queue<int,vector<int>,greater<int> > pq;
	int t,n,k,input;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    for(int i=0;i<n;i++){
	        cin>>input;
	        if(pq.size()==k){
	            if(input>pq.top()){
	                pq.pop();
	                pq.push(input);
	            }
	        }else{
	            pq.push(input);
	        }
	    }
	    vector<int> ans;
	    while(!pq.empty()){
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    for(int i=ans.size()-1;i>=0;i--){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
