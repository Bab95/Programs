class MyCalendar {
public:
    vector<pair<int,int> > intervals;
    MyCalendar() {
        intervals.reserve(1000);
    }

    bool book(int start, int end) {

        for(int i=0;i<intervals.size();++i){
            if(start>=intervals[i].first&&start<intervals[i].second){
                return false;
            }

            if(start<=intervals[i].first&&end>intervals[i].first){
                return false;
            }
        }

        pair<int,int> p;
        p.first = start;
        p.second = end;

        intervals.push_back(p);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
