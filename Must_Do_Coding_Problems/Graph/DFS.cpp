// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/
void dfs(int s, vector<int> g[], bool vis[])
{

    // Your code here
    cout<<s<<" ";
    vis[s] = true;
    for(int i=0;i<g[s].size();i++){
        if(!vis[g[s][i]]){
            dfs(g[s][i],g,vis);
        }
    }

}
