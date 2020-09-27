class Solution{
    public:
        bool Meetings(vector<vector<int> >& schedule){
            vector<pair<int,int> > meetings;
            meetings.reserve(schedule.size());
            pair<int,int> a;
            for(int i=0;i<schedule.size();++i){
                a.first = schedule[i][0];
                a.second = schedule[i][1];
            }
            sort(meetings.begin(),meetings.end());
            int prev_end = meetings[0].second;
            for(int i=1;i<meetings.size();++i){
                if(prev_end>meetings[i].first){
                    //overlapping.....
                    return false;
                }
                prev_end = meetings[i].second;
            }
        return true;
    }
};
/*
class Solution {
public:
    struct mycompare{
        bool operator()(const int& a,const int& b){
            return a>b;
        }
    };
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return true;
        }
        sort(intervals.begin(),intervals.end(),[](const auto &v1,const auto &v2){
            if(v1[0]==v2[0]){
                return v1[1]<v2[1];
            }
            return v1[0]<v2[0];
        });
        priority_queue<int,vector<int>,mycompare> pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<pq.top()){
                return false;
            }else if(intervals[i][0]>=pq.top()){
                pq.pop();
                pq.push(intervals[i][1]);
            }
        }
        return true;
    }
};

*/
