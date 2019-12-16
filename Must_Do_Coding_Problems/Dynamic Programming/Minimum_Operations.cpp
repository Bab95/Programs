#include <iostream>
#include <limits.h>
using namespace std;
int min(int a,int b){
    return a>b?b:a;
}

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int *arr = new int[n+1];
	    arr[0] = 0;
	    arr[1] = 1;
	    for(int i=2;i<=n;i++){
	        int add = arr[i-1]+1;
	        int div = (i%2==0)?arr[i/2]+1:INT_MAX;
	        arr[i] = min(add,div);
	    }
	    cout<<arr[n]<<endl;
	}

	return 0;
}
