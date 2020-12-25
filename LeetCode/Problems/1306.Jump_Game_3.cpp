class Solution {
public:
    void dfs(vector<int>& arr,int root,vector<bool>& visited,bool& ans){
        visited[root] = true;
        if(arr[root]==0){
            ans = true;
            return;
        }
        if(root+arr[root]>=0&&root+arr[root]<arr.size()&&!visited[root+arr[root]]){
            dfs(arr,root+arr[root],visited,ans);
        }
        if(root-arr[root]>=0&&root-arr[root]<arr.size()&&!visited[root-arr[root]]){
            dfs(arr,root-arr[root],visited,ans);
        }
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        bool ans = false;
        vector<bool> visited(n,false);
        visited[start] = true;
        dfs(arr,start,visited,ans);
        return ans;

    }
};
