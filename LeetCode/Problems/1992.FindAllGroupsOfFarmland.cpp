class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> farmland;
        for (int i=0;i<land.size();i++){
            for (int j=0;j<land[i].size();j++){
                if (land[i][j] == 1){
                    int x = i;
                    int y = j;
                    while (x < land.size() && land[x][j] == 1){
                        x ++;
                    }
                    while (y < land[i].size() && land[i][y] == 1){
                        y++;
                    }
                    for (int p=i;p<x;p++){
                        for(int q=j;q<y;q++){
                            land[p][q] = 2;
                        }
                    }
                    vector<int> currentland = {i,j,x-1,y-1};
                    farmland.push_back(currentland);
                }
            }
        }
        return farmland;
    }
};