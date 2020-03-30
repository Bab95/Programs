#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int input(vector<int>& a,int m){
    int sum = 0;
    for(int i=0;i<m;i++){
        cin>>a[i];
        sum+=a[i];
    }
    return sum;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>n>>m;
	    vector<int> arr(m),brr(n);
	    int sum1 = input(arr,m);
	    int sum2 = input(brr,n);
	    sort(arr.begin(),arr.end());
	    sort(brr.begin(),brr.end());
	    int i1=0,i2=0;
	    bool flag = false;
	    while(i1<arr.size()&&i2<brr.size()){
	        int tsum1 = sum1-arr[i1]+brr[i2];
	        int tsum2 = sum2-brr[i2]+arr[i1];
	        if(tsum1==tsum2){
	            cout<<1<<endl;
	            flag = true;
	            break;
	        }else if(tsum1<tsum2){
	            i2++;
	        }else{
	            i1++;
	        }

	    }
	    if(!flag){
	        cout<<-1<<endl;
	    }

	}
	return 0;
}
