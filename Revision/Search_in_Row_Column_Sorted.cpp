#include <iostream>
using namespace std;

int main() {
	//code
	int t,m,n,key;
	int mat[100][100];
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>mat[i][j];
	        }
	    }
	    cin>>key;
	    int i = 0;
	    int j = n-1;
	    bool found = false;
	    while(i<m&&j>=0){
	        if(mat[i][j]==key){
	            cout<<"1"<<endl;
	            found = true;
	            break;
	        }else if(key>mat[i][j]){
	            i++;
	        }else{
	            j--;
	        }
	    }
	    if(!found){
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
