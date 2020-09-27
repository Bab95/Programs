class Solution {
public:
    bool safe(int x,int y,vector<vector<bool>>& visited,vector<vector<char>>& image){
        if(x>=0&&x<image.size()&&y>=0&&y<image[0].size()&&image[x][y]=='1'&&!visited[x][y]){
            return true;
        }
        return false;
    }
    int calculate_area(pair<int,int>& lt,pair<int,int>& rb){
        //cout<<lt.first<<" "<<lt.second<<endl;
        //cout<<rb.first<<" "<<rb.second<<endl;
        int a = abs(rb.first-lt.first+1);
        int b = abs(rb.second-lt.second+1);
        return a*b;
    }
    int minArea(vector<vector<char>>& image, int x, int y) {
        pair<int,int> left_top = {INT_MAX,INT_MAX};
        pair<int,int> right_bottom = {-1,-1};
        int m = image.size();
        int n = image[0].size();
        cout<<m<<" "<<n<<endl;
        vector<vector<bool> > visited(m,vector<bool>(n,false));
        queue<pair<int,int> > q;
        q.push({x,y});
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        visited[x][y] = true;
        while(!q.empty()){
            auto current = q.front();
            visited[current.first][current.second] = true;
            q.pop();
            left_top.first = min(current.first,left_top.first);
            left_top.second = min(current.second,left_top.second);
            right_bottom.first = max(right_bottom.first,current.first);
            right_bottom.second = max(right_bottom.second,current.second);
            for(int k=0;k<4;++k){
                int nx = current.first + dx[k];
                int ny = current.second + dy[k];
                if(safe(nx,ny,visited,image)){
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        return calculate_area(left_top,right_bottom);

    }
};
/*

[["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","0","0","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","1","0","0","0","1","0","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","1","0","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","1","1","0","0","0","0","0","0","1","1","1","1","0","0","0","0","1","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","0","1","1","1","1","1","1","0","0","1","0","0","0","0","0","0","0","0","0","1","1","1","1","1","1","1","0","0","0","1","1","1","1","1","0","0","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","1","1","1","1","1","0","0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","1","0","0","1","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","0","0","1","1","1","1","1","1","1","0","0","0","0","1","1","1","1","1","1","1","0","0","0","1","1","1","1","1","1","1","0","1","0","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","0","0","0","1","1","1","0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","1","1","0","1","1","1","1","1","1","1","0","0","0","1","1","1","1","1","1","1","1","1","1","1","0","0","1","0","1","1","1","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","1","1","1","1","1","1","1","1","1","0","1","1","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","0","1","1","0","0","1","0","0","1","1","1","1","1","0","0","0","0","1","0","0","0","1","1","1","0","0","1","1","1","1","1","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","0","0","0","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0"],["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","0","0","0","0","1","1","1","1","1","1","1","1","0","0","0","0","0","1","0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","0","0","0","0","0","0","0","0","0","0","0"]]
17
63
*/
