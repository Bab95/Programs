#include <iostream>
using namespace std;

int main() {
	//code
	int t,m,n;
	int mat[11][11];
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>mat[i][j];
	        }
	    }
	    int N = m*n;
	    int index = 0;
	    int direction = 0;
	    int i,j,min_i,min_j,max_i,max_j;
	    min_i = 0;
	    min_j = 0;
	    max_i = m-1;
	    max_j = n-1;
	    i = min_i;
	    j = min_j;
		min_i = 1;
	    while(index<N){
	        index++;
	        cout<<mat[i][j]<<" ";
	        if(direction==0){
	            if(j==max_j){
	                direction = (direction+1)%4;
	                i++;
	                max_j--;
	            }else{
	            	j++;
				}
	        }else if(direction==1){
	            if(i==max_i){
	                direction = (direction+1)%4;
	                j--;
	                max_i--;
	            }else{
	            	i++;
				}
	        }else if(direction==2){
	            if(j==min_j){
	                direction = (direction+1)%4;
	                i--;
	                min_j++;
	            }else
	            	j--;
	        }else if(direction==3){
	            if(i==min_i){
	                direction = (direction+1)%4;
	                j = min_j;
					i = min_i;
					min_i++;
	            }else
	            	i--;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
