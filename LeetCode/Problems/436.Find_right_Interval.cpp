class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<vector<int>,int> > vec;
        int index = 0;
        for(auto it : intervals){
            vec.push_back({it,index});
            index++;
        }
        sort(vec.begin(),vec.end(),[](const auto& a,const auto& b){
            if(a.first[0]<b.first[0]){
                return true;
            }
            if(a.first[0]==b.first[0])
                return a.first[1]>b.first[1];
            return false;
        });
        /*for(auto it : vec){
            cout<<it.first[0]<<" "<<it.first[1]<<"--> "<<it.second<<endl;
        }*/
        vector<int> ans(intervals.size(),-1);
        for(int i=0;i<intervals.size();++i){
            for(int j=i+1;j<intervals.size();++j){
                if(vec[j].first[0]>=vec[i].first[1]){
                    ans[vec[i].second] = vec[j].second;
                    break;
                }
            }
        }
        return ans;
    }
};
