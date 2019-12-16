int min(int a,int b){
    return a<b?a:b;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int *arr = new int[n];
	    int *jumps = new int[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    jumps[0] = 0;
	    for(int i=1;i<n;i++){
	        jumps[i] = INT_MAX;
	        for(int j=0;j<i;j++){
	            if(i<=j+arr[j]&&jumps[j]!=INT_MAX){
	                jumps[i] = min(jumps[i],jumps[j]+1);
	            }
	        }
	    }
	    if(jumps[n-1]==INT_MAX){
	        cout<<"-1"<<endl;
	    }else{
	        cout<<jumps[n-1]<<endl;
	    }
	}
	return 0;
}
