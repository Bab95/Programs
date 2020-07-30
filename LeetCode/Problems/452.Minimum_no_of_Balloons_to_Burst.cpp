class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0){
            return 0;
        }
        sort(points.begin(),points.end(),[](const vector<int>& v1,const vector<int>& v2){
           if(v1[1]<v2[1]){
               return true;
           }else if(v1[1]==v2[1]){
               return v1[0]>v2[0];
           }
            return false;
        });
        int k = 0;
        int ans = 1;
        for(int i=1;i<points.size();++i){
            if(points[k][1]>=points[i][0]){
                continue;
            }else{
                ans++;
                k = i;
            }
        }
        return ans;
    }
};
/*
[[10,16],[2,8],[1,6],[7,12]]
[[1,6],[5,12],[2,8],[4,16]]
[[10,16],[6,8],[1,6],[7,12]]
[[7,9]]
[]
*/
