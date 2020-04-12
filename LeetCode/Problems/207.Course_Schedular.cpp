class Solution {
public:
    void topologicalSort(vector<vector<int>>& graph,int i,vector<bool>& visited,vector<bool>& instk,int& possible){
        visited[i] = true;
        instk[i] = true;
        for(int j=0;j<graph[i].size();++j){
            if(instk[graph[i][j]]){
                possible = -1;
                return;
            }
            if(!visited[graph[i][j]]){
                topologicalSort(graph,graph[i][j],visited,instk,possible);
            }
        }
        instk[i] = false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,false);
        vector<bool> instk(numCourses,false);
        vector<vector<int> > graph(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();++i){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int possible = 1;
        for(int i=0;i<numCourses;++i){
            if(!visited[i]){
                topologicalSort(graph,i,visited,instk,possible);
            }
            if(possible==-1){
                return false;   
            }
        }
        return true;
    }
};