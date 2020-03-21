#include <iostream>
#include <vector>
using namespace std;
bool issafe(int x,int y,vector<vector<bool> >& visited,int val,vector<vector<int> >& mat){
    if(x>=0&&x<mat.size()&&y>=0&&y<mat[0].size()&&!visited[x][y]&&mat[x][y]==val){
        return true;
    }
    return false;
}
void dfs(vector<vector<int> >& mat,vector<vector<bool> >& visited,int x,int y,int k,int coor[],int val){
    mat[x][y] = k;
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        if(issafe(x+coor[i],y+coor[i+1],visited,val,mat)){
            dfs(mat,visited,x+coor[i],y+coor[i+1],k,coor,val);
        }
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    vector<vector<int> > mat(m,vector<int>(n,0));
	    vector<vector<bool> > visited(m,vector<bool>(n,0));
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>mat[i][j];
	        }
	    }
	   int x,y,k;
	   cin>>x>>y>>k;
	   int coor[] = {0,-1,0,1,0};
	   int val = mat[x][y];
	   dfs(mat,visited,x,y,k,coor,val);
	   for(int i=0;i<m;i++){
	       for(int j=0;j<n;j++){
	           cout<<mat[i][j]<<" ";
	       }
	   }
	   cout<<endl;
	}
	return 0;
}
