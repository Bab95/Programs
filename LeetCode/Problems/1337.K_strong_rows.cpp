class Solution {
public:
    struct compareMIN{
        bool operator()(const pair<int,int>& p1,const pair<int,int>& p2){
            if(p1.first>p2.first){
                return true;
            }else if(p1.first==p2.first){
                if(p1.second>p2.second){
                    return true;
                }
            }
            return false;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int> >,compareMIN> pq;
        for(int i=0;i<mat.size();++i){
            int count = 0;
            for(int j=0;j<mat[i].size();++j){
                count += mat[i][j];
            }
            pq.push(make_pair(count,i));
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            if(ans.size()==k){
                return ans;
            }
        }
        return ans;
    }
};
