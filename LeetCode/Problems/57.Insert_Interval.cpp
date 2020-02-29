bool sortcol(const vector<int>& v1,const vector<int>& v2){
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),sortcol);
        struct inter current;
        current.start = intervals[0][0];
        current.end = intervals[0][1];
        vector<vector<int> > result;
        vector<int> tmp(2);
        /*for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }*/
        for(int i=1;i<intervals.size();i++){
            if(current.end>=intervals[i][0]){
                current.end = max(intervals[i][1],current.end);
            }else{
                tmp[0] = current.start;
                tmp[1] = current.end;
                result.push_back(tmp);
                current.start = intervals[i][0];
                current.end = intervals[i][1];
            }
        }
        tmp[0] = current.start;
        tmp[1] = current.end;
        result.push_back(tmp);
        return result;
    }
};
