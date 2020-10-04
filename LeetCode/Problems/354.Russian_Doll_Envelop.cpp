class Solution {
public:
    int area(pair<int,int>& a){
        return a.first*a.second;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0){
            return 0;
        }
        vector<pair<int,int>> vec(envelopes.size());
        for(int i=0;i<envelopes.size();++i){
            vec[i] = make_pair(envelopes[i][0],envelopes[i][1]);
        }
        sort(vec.begin(),vec.end(),[](pair<int,int>& a,pair<int,int>& b){
            int aa = a.first*a.second;
            int bb = b.first*b.second;
            if(a.first==b.first){
                return a.second<b.second;
            }
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.first<b.first;
        });
        //int c = 0;
        //for(auto it:vec){
        //    cout<<c<<" -> "<<it.first<<" "<<it.second<<endl;
        //    c++;
        //}
        int n = vec.size();
        vector<int> dp(n,1);
        int ans = 1;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(vec[j].first<vec[i].first&&vec[j].second<vec[i].second&&dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
            ans = max(ans,dp[i]);
        }
        //for(int i=0;i<dp.size();++i){
        //    cout<<dp[i]<<" ";
        //}
        return ans;
    }
};
