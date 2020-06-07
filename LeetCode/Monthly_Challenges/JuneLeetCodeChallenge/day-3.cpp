class Solution {
public:
    static bool compare(const pair<int,int>& p1,const pair<int,int>& p2){
        if(p1.second-p1.first>p2.second-p2.first){
            return true;
        }
        return false;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int> > arr;
        int n = costs.size();
        for(int i=0;i<n;++i){
            arr.emplace_back(make_pair(costs[i][0],costs[i][1]));
        }
        int ans = 0;
        sort(arr.begin(),arr.end(),compare);
        for(auto it=arr.begin();it!=arr.end();++it){
            cout<<it->first<<" "<<it->second<<endl;
        }
        int a = 0;
        int b = 0;
        int one = n/2;
        int i = 0;
        for(i=0;i<n;++i){
           if(i<n/2){
               ans+=arr[i].first;
           }else{
               ans+=arr[i].second;
           }
        }
        cout<<"\n--------end---------"<<endl;
        return ans;
    }
};
