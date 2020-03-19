class Solution {
public:
    typedef pair<int,int> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > pq;
        //priority_queue<pi,vector<pi>,greater<pi> > pq;
        priority_queue<pi> pq;
        for(int i=0;i<points.size();i++){
            int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if(i<K){
                pair<int,int> p;
                p.first = distance;
                p.second = i;
                pq.push(p);
            }else{
                if(distance<pq.top().first){
                    pq.pop();
                    pair<int,int> p;
                    p.first = distance;
                    p.second = i;
                    pq.push(p);
                }
            }
        }

        vector<vector<int> > result;
        pair<int,int> o;
        vector<int> resPoint(2,0);
        while(!pq.empty()){
            o = pq.top();
            pq.pop();
            resPoint[0] = points[o.second][0];
            resPoint[1] = points[o.second][1];
            result.push_back(resPoint);
        }
        return result;
    }
};
