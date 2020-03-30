#include <iostream>
#include <vector>
using namespace std;
void printPath(vector<int>& path){
    for(int i=0;i<path.size();i++){
        cout<<path[i];
    }
    cout<<endl;
}
bool safe(int x,int y,vector<vector<bool> >& visited){
    if(x>=0&&x<=visited.size()-1&&y>=0&&y<=visited[0].size()&&!visited[x][y]){
        return true;
    }
    return false;
}
void findPath(vector<vector<bool> >& visited,int x,int y,int *n_path){
    //cout<<"find("<<x<<","<<y<<")"<<endl;
    if(x==visited.size()-1&&y==visited[0].size()-1){
        *n_path = *n_path+1;
        return;
    }
    visited[x][y] = true;
    if(safe(x+1,y,visited)){
        findPath(visited,x+1,y,n_path);
    }
    if(safe(x,y+1,visited)){
        findPath(visited,x,y+1,n_path);
    }
    visited[x][y] = false;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    int npaths = 0;
	    vector<vector<bool> > visited(m,vector<bool>(n,false));
	    findPath(visited,0,0,&npaths);
	    cout<<npaths<<endl;
	}
	return 0;
}
