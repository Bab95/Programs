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