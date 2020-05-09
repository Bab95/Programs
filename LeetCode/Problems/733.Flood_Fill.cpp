class Solution {
public:
    vector<int> dx = {0,1,0,-1,0};
    bool safe(vector<vector<int> >& image,int x,int y,int src){
        if(x>=0&&x<image.size()&&y>=0&&y<image[0].size()&&image[x][y]==src){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int> >& image,int sr,int sc,int newColor,int color){
        image[sr][sc] = newColor;
        //visited[sr][sc] = true;
        for(int i=0;i<4;i++){
            int nx = sr+dx[i];
            int ny = sc+dx[i+1];
            if(safe(image,nx,ny,color)){
                dfs(image,nx,ny,newColor,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color!=newColor){
            dfs(image,sr,sc,newColor,color);
        }

        return image;
    }
};
