class Solution {
public:
    void dfs(vector<vector<int> >& rooms,int node,vector<bool>& visited,int& count){
        visited[node] = true;
        count++;
        for(auto key : rooms[node]){
            if(!visited[key]){
                dfs(rooms,key,visited,count);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        int count = 0;
        dfs(rooms,0,visited,count);
        if(count<rooms.size()){
            return false;
        }
        return true;
    }
};
