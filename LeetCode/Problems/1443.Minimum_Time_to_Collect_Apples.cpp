class Solution {
public:
    int dfs(vector<vector<int> >& graph,int i,vector<bool>& hasApple){
        //child and no apple so no need to add time...
        if(graph[i].size()==0){
            //leaf node....
            if(hasApple[i]){
                return 2;
            }else{
                return 0;
            }
        }
        int tmp = 0;
        for(int c=0;c<graph[i].size();c++){
            tmp+=dfs(graph,graph[i][c],hasApple);
        }
        if(tmp==0&&!hasApple[i]){
            return 0;
        }
        else if(hasApple[i]||tmp!=0){
            return tmp+2;
        }
        return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int> > graph(n,vector<int>());
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        int time = 0;
        for(int c=0;c<graph[0].size();++c){
            time += dfs(graph,graph[0][c],hasApple);
        }
        return time;
    }
};
