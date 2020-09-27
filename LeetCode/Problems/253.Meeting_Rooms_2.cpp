class Solution {
public:
    struct mycompare{
        bool operator()(const int& a,const int& b){
            return a>b;
        }
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](const auto& v1,const auto& v2){
            if(v1[0]==v2[0]){
                return v1[1]<v2[1];
            }
            return v1[0]<v2[0];
        });
        priority_queue<int,vector<int>,mycompare> pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]>=pq.top()){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};
