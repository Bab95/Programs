#include <iostream>
#include <vector>
using namespace std;

int main() {
	//code
	int t,n;
	//vector<vector<int> > mat;
	//vector<int> tmp;
	cin>>t;
	int x;
	while(t--){
	    cin>>n;
	    vector<int> mat[2*n-1];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>x;
	            mat[i+j].push_back(x);
	        }
	    }
	    for(int i=0;i<2*n-1;i++){
	        for(int j=0;j<mat[i].size();j++){
	            cout<<mat[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
