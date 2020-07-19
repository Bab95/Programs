class Solution {
public:
    void topological_Sort(vector<vector<int> >& graph,vector<int>& res,int i,vector<bool>& visited,vector<bool>& instk,bool& possible){
        visited[i] = true;
        instk[i] = true;
        for(auto child : graph[i]){
            if(instk[child]){
                //not possible as cycle detected.....
                possible = false;
                return;
            }
            if(!visited[child]){
                topological_Sort(graph,res,child,visited,instk,possible);
            }
        }
        instk[i] = false;
        res.push_back(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses+1,vector<int>());
        vector<int> indegree(numCourses,0);
        for(auto it : prerequisites){
            int a = it[0];
            int b = it[1];
            indegree[it[1]]++;
            graph[a].push_back(b);
        }
        unordered_set<int> candidates;
        for(int i=0;i<indegree.size();++i){
            if(indegree[i]==0){
                candidates.insert(i);
            }
        }
        vector<int> res;
        vector<bool> visited(numCourses,false);
        vector<bool> instk(numCourses,false);
        bool flag = true;
        for(int i=0;i<numCourses;++i){

            if(!visited[i])
                topological_Sort(graph,res,i,visited,instk,flag);
            if(flag==false){
                return {};
            }
        }
        return res;
    }
};
