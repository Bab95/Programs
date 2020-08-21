class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){
            if(a[0]<b[0]){
                return true;
            }
            //if equal or greater then only overlapping occurs when end is smaller than prev's
            return a[1]<b[1];
        });
        int k = 0;
        int ans = 0;
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<intervals[k][1]){
                ans++;
            }else{
                k = i;
            }
        }
        return ans;
    }
};
