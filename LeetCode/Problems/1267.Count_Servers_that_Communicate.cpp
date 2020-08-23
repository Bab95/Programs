class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row_sum(m,0),column_sum(n,0);
        int total_servers = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                row_sum[i] += grid[i][j];
            }
        }

        for(int j=0;j<n;++j){
            for(int i=0;i<m;++i){
                column_sum[j] += grid[i][j];
            }
        }

        int ans = 0;
        for(int i=0;i<m;++i){
            if(row_sum[i]==1){
                for(int j=0;j<n;++j){
                    if(grid[i][j]==1&&column_sum[j]==1){
                        ans++;
                    }
                }
            }
            total_servers += row_sum[i];
        }
        total_servers -= ans;
        return total_servers;
    }
};
