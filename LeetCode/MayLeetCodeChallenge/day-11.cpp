class Solution {
public:
    bool safe(vector<vector<int> >& image,int x,int y,int color){
        if(x>=0&&x<image.size()&&y>=0&&y<image[0].size()&&image[x][y]==color){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int > >& image,int sr,int sc,int color,int newColor){
        image[sr][sc] = newColor;
        static int row[] = {0,0,1,-1};
        static int col[] = {1,-1,0,0};
        for(int i=0;i<4;++i){
            int x = sr+row[i];
            int y = sc+col[i];
            if(safe(image,x,y,color)){
                dfs(image,x,y,color,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color  = image[sr][sc];
        if(color==newColor){
            return image;
        }
        if(image.size()==0){
            return image;
        }
        dfs(image,sr,sc,color,newColor);
        return image;
    }
};
