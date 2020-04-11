#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    long long int sum = 0;
    long long int square_sum = 0;
    long long int actual_sum = 0;
    long long int actual_sq_sum = 0;
    for(int i=0;i<n;i++){
       sum+=arr[i];
       square_sum+=(arr[i]*arr[i]);
       actual_sum+=(i+1);
       actual_sq_sum += ((i+1)*(i+1));
    }
    //cout<<actual_sum<<" "<<actual_sq_sum<<endl;
    long long int x2y2 = actual_sq_sum-square_sum;
    long long int xy = actual_sum-sum;
    int sumof2 = x2y2/xy;
    int missing = (sumof2+xy)/2;
    int repeat= sumof2-missing;
    cout<<repeat<<" "<<missing<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
