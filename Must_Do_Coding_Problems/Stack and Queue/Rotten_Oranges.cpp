#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool safe(vector<vector<int> >& grid,int x,int y){
    if(x>=0&&x<grid.size()&y>=0&&y<grid[0].size()&&grid[x][y]==1){
        return true;
    }
    return false;
}
int calculateDays(vector<vector<int> >& grid){
    int r = grid.size();
    int c = grid[0].size();
    queue<pair<int,int> > q;
    //vector<vector<bool> > marked(r,vector<bool>(c,false));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==2){
                pair<int,int> p;
                p.first = i;
                p.second = j;
                q.push(p);
                //marked[i][j] = true;
            }
        }
    }
    int res = 0;
    int dxy[] = {0,1,0,-1,0};
    while(!q.empty()){
        int n = q.size();
        //cout<<"n "<<n<<": ";
        for(int i=0;i<n;i++){
            pair<int,int> current = q.front();
           // cout<<"("<<current.first<<","<<current.second<<"), ";
            q.pop();
            for(int j=0;j<4;j++){
                if(safe(grid,current.first+dxy[j],current.second+dxy[j+1])){
                    grid[current.first+dxy[j]][current.second+dxy[j+1]] = 2;
                    pair<int,int> new_point;
                    new_point.first = current.first+dxy[j];
                    new_point.second = current.second+dxy[j+1];
                    q.push(new_point);
                }
            }

        }
        //cout<<endl;
        res++;
    }
    /*for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
    }
    return res-1;
}
int main() {
	//code
	int t;
	int r,c;
	cin>>t;
	while(t--){
	    cin>>r>>c;
	    vector<vector<int> > grid(r,vector<int>(c,0));
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            cin>>grid[i][j];
	        }
	    }
	   int res = calculateDays(grid);
	   cout<<res<<endl;
	}
	return 0;
}
