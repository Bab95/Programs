#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;
int binary(int arr[],int l,int n,int key){
    if(l<=n){
        int mid=(l+n)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            return binary(arr,mid+1,n,key);
        }else{
            return binary(arr,l,mid-1,key);
        }
    }
    return -1;

}
int fun(int arr[],int arr1[],int n,int m1,int key){

    sort(arr,arr+n);
    sort(arr1,arr1+m1);
    //unordered_map<int,int>m;
    //vector<pair<int,int> > answers;
    int count = 0;
    for(int i=0;i<n;i++){
        int f=(key-arr[i]);
        int index=binary(arr1,0,m1,f);
        if(index!=-1){
            count++;
            if(count>1){
                cout<<", ";
            }

            cout<<arr[i]<<" "<<arr1[index];
        }
    }
    return count;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m,key;
	    cin>>n>>m>>key;
	    int arr[n];
	    int arr1[m];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(int i=0;i<m;i++){
	        cin>>arr1[i];
	    }
	    int count = fun(arr,arr1,n,m,key);
	    if(count==0){
	        cout<<-1;
	    }
	    cout<<endl;
	}
	return 0;
}
