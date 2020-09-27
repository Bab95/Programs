class Solution {
public:
    void bfs(unordered_map<int,vector<int>>& graph,int kill,vector<int>& ans){
        queue<int> q;
        q.push(kill);

        while(!q.empty()){
            int current = q.front();
            q.pop();
            ans.push_back(current);
            for(auto child:graph[current]){
                q.push(child);
            }
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int> > graph;
        for(int i=0;i<pid.size();++i){
            graph[ppid[i]].push_back(pid[i]);
        }
        vector<int> ans;
        bfs(graph,kill,ans);
        return ans;
    }
};
