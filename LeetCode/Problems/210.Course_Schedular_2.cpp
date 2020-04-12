class Solution {
public:
    void topologicalSort(vector<vector<int> >& graph,int i,vector<bool>& visited,vector<int>& ans,int& index,vector<bool>& instk,int& possible){
        visited[i] = true;
        instk[i] = true;
        for(int j=0;j<graph[i].size();++j){
            if(instk[graph[i][j]]){
                possible = -1;
                return;
            }
            if(!visited[graph[i][j]]){
                topologicalSort(graph,graph[i][j],visited,ans,index,instk,possible);
            }
        }
        instk[i] = false;
        ans[index] = i;
        ++index;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();++i){
          graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses,false);
        vector<int> ans(numCourses);
        vector<bool> instk(numCourses,false);
        //ans.reserve(numCourses);
        int index = 0;
        int possible = 1;
        for(int i=0;i<numCourses;++i){
            if(!visited[i]){
                topologicalSort(graph,i,visited,ans,index,instk,possible);
            }
            if(possible==-1){
                return {};
            }
        }
        cout<<possible<<endl;
        /*cout<<index<<endl;
        for(int i=0;i<ans.size();++i){
            cout<<ans[i]<<" ";
        }*/
        return ans;
    }
};