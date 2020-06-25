class Solution {
public:
    void dfs(unordered_map<int,vector<int> >& graph,int node,unordered_map<int,bool>& visited,int& count){
        visited[node] = true;
        count++;
        for(int i=0;i<graph[node].size();++i){
            int child = graph[node][i];
            if(!visited[child]){
                dfs(graph,child,visited,count);
            }
        }
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,vector<int> > graph;
        unordered_map<int,bool> visited;
        for(int i=0;i<nums.size();++i){
            graph[nums[i]] = {};
            visited[nums[i]] = false;
        }

        for(int i=0;i<nums.size();++i){
            if(graph.count(nums[i]-1)!=0){
                graph[nums[i]-1].push_back(nums[i]);
                graph[nums[i]].push_back(nums[i]-1);
            }
            if(graph.count(nums[i]+1)!=0){
                graph[nums[i]+1].push_back(nums[i]);
                graph[nums[i]].push_back(nums[i]+1);
            }
        }
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            if(!visited[nums[i]]){
                int count = 0;
                dfs(graph,nums[i],visited,count);
                ans = max(ans,count);
            }
        }
        return ans;
    }

};
