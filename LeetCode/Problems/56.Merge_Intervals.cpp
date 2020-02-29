bool sortcol(vector<int>& v1,vector<int>& v2){
        return v1[0]<v2[0];
}
class Solution {
public:
    struct inter{
        int start;
        int end;
    };
    int max(int a,int b){
        return a>b?a:b;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > result;
        if(intervals.size()==0){
            return result;
        }
        sort(intervals.begin(),intervals.end(),sortcol);
        struct inter current;
        current.start = intervals[0][0];
        current.end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=current.end){
                current.end = max(intervals[i][1],current.end);
            }else{
                vector<int> tmp(2);
                tmp[0] = current.start;
                tmp[1] = current.end;
                result.push_back(tmp);
                current.start = intervals[i][0];
                current.end = intervals[i][1];
            }
        }
        vector<int> tmp(2);
        tmp[0] = current.start;
        tmp[1] = current.end;
        result.push_back(tmp);
        return result;
    }
};
