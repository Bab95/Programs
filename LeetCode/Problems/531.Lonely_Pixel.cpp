class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        int ans = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(picture[i][j]=='B'){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(picture[i][j]=='B'&&rows[i]==1&&cols[j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
