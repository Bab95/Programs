class Solution {
public:
    struct compare{
        bool operator()(pair<int,vector<int> >& p1,pair<int,vector<int> >& p2){
            if(p1.first<p2.first){
                return false;
            }
            return true;
        }
    };
    int min(int a,int b){
        return a<b?a:b;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,vector<int> >,vector<pair<int,vector<int> > >,compare> pq;
        vector<int> idx(mat.size(),0);
        map<vector<int>,int> visited;
        int sum = 0;
        for(int i=0;i<mat.size();++i){
            sum += mat[i][0];
        }
        pq.push(make_pair(sum,idx));
        visited[idx] = 1;
        int ans = INT_MIN;
        while(k>0&&!pq.empty()){
            k--;
            pair<int,vector<int> > p = pq.top();
            pq.pop();

            ans = p.first;
            if(k==0){
                return ans;
            }
            int current_sum = p.first;
            idx = p.second;
            int next_min_sum = INT_MAX;
            for(int i=0;i<mat.size();++i){
                idx = p.second;
                if(idx[i]+1<mat[i].size()){
                    next_min_sum = current_sum-mat[i][idx[i]]+mat[i][idx[i]+1];
                    idx[i] = idx[i]+1;
                    if(visited.find(idx)==visited.end()){
                        visited[idx] = 1;
                        pq.push(make_pair(next_min_sum,idx));
                    }
                }
            }

        }
        return ans;
    }
};
