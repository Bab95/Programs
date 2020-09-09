/*
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

*/



/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    struct mycomparator{
        //MIN HEAP COMPARATOR
        bool operator()(const pair<Interval,pair<int,int> >&p1,const pair<Interval,pair<int,int> >& p2)const{
            if(p1.first.start==p2.first.start){
                return p1.first.end>p2.first.end;
            }
            return p1.first.start>p2.first.start;
        }
    };
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<pair<Interval,pair<int,int> >,vector<pair<Interval,pair<int,int> >>,mycomparator> pq;
        for(int i=0;i<schedule.size();++i){
            pq.push({schedule[i][0],{i,0}});
        }
        vector<Interval> merged;
        while(!pq.empty()){
            auto _first = pq.top();
            //cout<<_first.first.start<<" "<<_first.first.end<<endl;
            pq.pop();
            int r = _first.second.first;
            int c = _first.second.second;
            if(r!=INT_MAX&&c!=INT_MAX){
                if(c!=schedule[r].size()-1){
                    pair<Interval,pair<int,int> > next;
                    next.first = schedule[r][c+1];
                    next.second = {r,c+1};
                    pq.push(next);
                }
            }

            if(!pq.empty()){
                auto _second = pq.top();
                //cout<<_second.first.start<<" "<<_second.first.end<<endl;
                pq.pop();
                int r = _second.second.first;
                int c = _second.second.second;
                if(r!=INT_MAX&&c!=INT_MAX){
                    if(c!=schedule[r].size()-1){
                        pair<Interval,pair<int,int> > next;
                        next.first = schedule[r][c+1];
                        next.second = {r,c+1};
                        pq.push(next);
                    }
                }
                if(_first.first.end>=_second.first.start){
                    pair<Interval,pair<int,int> > next;
                    next.first.start = _first.first.start;
                    next.first.end = max(_second.first.end,_first.first.end);
                    next.second = {INT_MAX,INT_MAX};
                    pq.push(next);
                }else{
                    pq.push(_second);
                    merged.push_back(_first.first);

                }
            }else{
                merged.push_back(_first.first);
            }
        }
        vector<Interval> ans;
        /*
        cout<<"------------------"<<endl;
        for(auto it:merged){
            cout<<it.start<<" "<<it.end<<endl;
        }
        */
        Interval current = merged[0];
        for(int i=1;i<merged.size();++i){
            if(merged[i].start>current.end){
                Interval itr;
                itr.start = current.end;
                itr.end = merged[i].start;
                ans.push_back(itr);
                current = merged[i];
            }
        }
        return ans;
    }
};
