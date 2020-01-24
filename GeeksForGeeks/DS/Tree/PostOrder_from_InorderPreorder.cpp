#include <iostream>
using namespace std;
int findIndex(int arr[],int val,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}
void postOrder(int in[],int pre[],int n){
    int index = findIndex(in,pre[0],n);
    if(index!=0){
        postOrder(in,pre+1,index);
    }
    if(index!=n-1){
        postOrder(in+index+1,pre+index+1,n-index-1);
    }
    cout<<pre[0]<<" ";
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int in[n],pre[n];
	    for(int i=0;i<n;i++){
	        cin>>in[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>pre[i];
	    }
	    postOrder(in,pre,n);
	    cout<<endl;
	}
	return 0;
}
