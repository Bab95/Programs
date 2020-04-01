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
	    bool flag = false;
	    for(int j=0;j<n;j++){
	        if(mmap.count(brr[j])==0){
	            flag = true;
	            break;
	        }
	    }
	    if(flag){
	        cout<<"No"<<endl;
	    }else{
	        cout<<"Yes"<<endl;
	    }
	}
	return 0;
}
