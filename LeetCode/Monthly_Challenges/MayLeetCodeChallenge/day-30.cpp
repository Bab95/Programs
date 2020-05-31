class Solution {
public:
    long long int distance(vector<int>& p1){
        return (p1[0]*p1[0])+(p1[1]*p1[1]);
    }
    struct compare{
        bool operator()(const pair<long long int,vector<int> >& p1,const pair<long long int,vector<int> >& p2){
            if(p1.first<p2.first){
                return true;
            }
            return false;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int> > ans;
        priority_queue<pair<long long int,vector<int> >,vector<pair<long long int,vector<int> > >,compare> pq;
        for(int i=0;i<points.size();++i){
            if(pq.size()<k){
                pq.push(make_pair(distance(points[i]),points[i]));
            }else{
                long long int dist = distance(points[i]);
                if(dist<pq.top().first){
                    pq.pop();
                    pq.push(make_pair(distance(points[i]),points[i]));
                }
                //otherwise leave it..
            }
        }
        while(!pq.empty()){
            auto it = pq.top();
            cout<<it.first<<endl;
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};
