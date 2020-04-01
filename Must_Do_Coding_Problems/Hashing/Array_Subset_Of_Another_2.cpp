#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int main() {
	//code
	int t,m,n;
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    vector<int> arr(m);
	    vector<int> brr(n);
	    input(arr,m);
	    input(brr,n);
	    unordered_map<int,int> mmap;
	    for(int i=0;i<m;i++){
	        mmap[arr[i]]+=1;
	    }
	    for(int i=0;i<n;i++){
	        mmap[brr[i]]+=1;
	    }
	    bool flag = true;
	    for(int i=0;i<n;i++){
	        if(mmap[brr[i]]!=2){
	            flag = false;
	            break;
	        }
	    }
	    if(flag){
	        cout<<"Yes"<<endl;
	    }else{
	        cout<<"No"<<endl;
	    }

	}
	return 0;
}
