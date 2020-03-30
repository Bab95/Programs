// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* You have to complete this function*/

/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code here
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            int NODE = q.front();
            cout<<NODE<<" ";
            q.pop();
            //vis[NODE] = true;
            for(int i=0;i<adj[NODE].size();i++){
                if(!vis[adj[NODE][i]]){
                    vis[adj[NODE][i]] = true;
                    q.push(adj[NODE][i]);
                }
            }
        }
    }

}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        bfs(0, adj, vis, N);

        cout<<endl;

    }
}

  // } Driver Code Ends
