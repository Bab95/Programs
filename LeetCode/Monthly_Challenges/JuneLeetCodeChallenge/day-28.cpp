class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string> > graph;
        for(auto it : tickets){
            graph[it[0]].insert(it[1]);
        }
        vector<string> ans;
        stack<string> stk;
        stk.push("JFK");
        while(!stk.empty()){
            auto from = stk.top();
            if(!graph[from].size()){
                ans.push_back(from);
                stk.pop();
            }else{
                auto to = graph[from].begin();
                stk.push(*to);
                graph[from].erase(to);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
