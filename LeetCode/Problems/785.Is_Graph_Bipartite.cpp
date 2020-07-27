#define red 1
#define blue 2
#define no_color 0
class Solution {
public:
    bool bfs(int node,vector<vector<int> >& graph,vector<int>& colored){
        colored[node] = red;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;++i){
                int current = q.front();
                q.pop();
                int current_color = colored[current];
                int child_color = 0;
                if(current_color==red){
                    child_color = blue;
                }else{
                    child_color = red;
                }
                for(auto child : graph[current]){
                    if(colored[child]==no_color){
                        colored[child] = child_color;
                        q.push(child);
                    }else if(colored[child]==current_color){
                        return false;
                    }else if(colored[child]==child_color){
                        continue;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(),0);
        bool ans = true;
        for(int i=0;i<graph.size();++i){
            if(colored[i]==no_color){
                ans &= bfs(i,graph,colored);
            }
        }
        return ans;
    }
};
