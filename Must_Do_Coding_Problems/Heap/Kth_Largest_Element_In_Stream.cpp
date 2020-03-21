#include <iostream>
#include <queue>
using namespace std;
int getKthElement(priority_queue<int,vector<int>,greater<int> >& pq,int input,int k){
    if(pq.size()<k){
        pq.push(input);
        if(pq.size()==k){
            return pq.top();
        }
        return -1;
    }else{
        if(input>pq.top()){
            pq.pop();
            pq.push(input);
        }
        return pq.top();
    }
    return -1;
}
int main() {
	//code
	int t,k,n;
	int input;
	cin>>t;
	while(t--){
	    cin>>k>>n;
	    priority_queue<int,vector<int>,greater<int> > pq;
	    for(int i=0;i<n;i++){
	        cin>>input;
	        cout<<getKthElement(pq,input,k)<<" ";

	    }
	    cout<<endl;
	}
	return 0;
}
