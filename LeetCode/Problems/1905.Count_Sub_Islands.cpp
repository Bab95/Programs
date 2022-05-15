class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int count = 0;
        vector<vector<pair<int,int>>> ans;
        for (int i=0;i<grid1.size();i++){
            for (int j=0;j<grid1[i].size();j++){
                if (grid1[i][j] == 1 && grid2[i][j] == 1){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    bool is_sub_island = true;
                    vector<pair<int,int>> _current;
                    while (!q.empty()) {
                        pair<int,int> current = q.front();
                        _current.push_back(current);
                        q.pop();
                        for (int k=0;k<4;k++){
                            int nx = current.first + dx[k];
                            int ny = current.second + dy[k];
                            if (nx >=0 && nx < grid1.size() && ny >=0 && ny < grid1[i].size()) {
                                if (grid1[nx][ny] == 1 && grid2[nx][ny] == 1) {
                                    q.push({nx,ny});
                                    grid2[nx][ny] = 0;
                                }else if (grid1[nx][ny] == 0 && grid2[nx][ny] == 1){
                                    is_sub_island = false;
                                }
                            }
                        }
                    }
                    if (is_sub_island){
                        count ++;
                        ans.push_back(_current);
                    }
                }
            }
        }
        /*
        int index = 2;
        for (int i=0;i<ans.size();i++){
            for (int j=0;j<ans[i].size();j++){
                auto x = ans[i][j];
                grid1[x.first][x.second] = index;
            }
            index++;
        }

        for (int i=0;i<grid1.size();i++){
            for (int j=0;j<grid1.size();j++){
                cout << grid1[i][j] <<" ";
            }
            cout << endl;
        }
            */
        return count;
    }
};
