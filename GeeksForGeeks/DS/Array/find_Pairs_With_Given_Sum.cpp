#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;
int fun(vector<int>& arr,vector<int>& arr2,int key){
    unordered_map<int,int> mmap;
    for(int i=0;i<arr2.size();++i){
        mmap[arr2[i]]+=1;
    }
    int res = 0;
    sort(arr.begin(),arr.end());
    if(mmap.find(key-arr[0])!=mmap.end()){
        cout<<arr[0]<<" "<<key-arr[0];
        mmap.erase(key-arr[0]);
        res++;
    }
    for(int i=1;i<arr.size();++i){
        int kk = key-arr[i];

        if(mmap.find(kk)!=mmap.end()){
            if(res>0)
                cout<<", ";
            res++;
            cout<<arr[i]<<" "<<kk;
            mmap.erase(kk);
        }
    }
    return res;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m,key;
	    cin>>n>>m>>key;
	    vector<int> arr(n);
	    vector<int> arr1(m);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(int i=0;i<m;i++){
	        cin>>arr1[i];
	    }
	    int count = fun(arr,arr1,key);
	    if(count==0){
	        cout<<-1;
	    }
	    cout<<endl;
	}
	return 0;
}
