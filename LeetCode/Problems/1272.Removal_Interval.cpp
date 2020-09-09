/*
Given a sorted list of disjoint intervals, each interval intervals[i] = [a, b] represents the set of real numbers x such that a <= x < b.

We remove the intersections between any interval in intervals and the interval toBeRemoved.

Return a sorted list of intervals after all such removals.
*/
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int> > ans;
        int x = toBeRemoved[0];
        int y = toBeRemoved[1];
        for(int i=0;i<intervals.size();++i){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(s>y||e<x){
                ans.push_back({s,e});
            }else if(x>s&&y<e){
                ans.push_back({s,x});
                ans.push_back({y,e});
            }else if(s<x&&e<=y){
                ans.push_back({s,x});
            }else if(s>=x&&y<e){
                ans.push_back({y,e});
            }
        }
        return ans;
    }
};
