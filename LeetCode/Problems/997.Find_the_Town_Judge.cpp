class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trust_to(N+1,0);
        vector<int> trusted_by(N+1,0);
        for(int i=0;i<trust.size();++i){
            trust_to[trust[i][0]]+=1;
            trusted_by[trust[i][1]]+=1;
        }
        int ans = -1;
        for(int i=1;i<=N;++i){
            if(trust_to[i]==0&&trusted_by[i]==N-1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
