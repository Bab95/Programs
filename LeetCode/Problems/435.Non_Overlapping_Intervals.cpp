class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& v1,const vector<int>& v2){
           if(v1[0]<v2[0]){
               return true;
           }else if(v1[0]==v1[0]){
               return v1[1]<v2[1];
           }
            return false;
        });
        int ans = 0;
        int k = 0;
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<intervals[k][1]){
                ans++;
            }else{
                //not overlapping....
                k = i;
            }
        }
        return ans;
    }
};
