#include <bits/stdc++.h>
const int _max = 1e5 + 5;
using namespace std;
vector<pair<int,int> > graph[_max];
bool visited[_max];
vector<int> subtrees;
int subtree_size[_max];
void dfs(int node,bool infect){
    /*cout<<"("<<node<<", ";
    if(infect){
        cout<<"true)"<<endl;
    }else{
        cout<<"false)"<<endl;
    }*/
    visited[node] = true;
    subtree_size[node] = 1;
    for(auto child : graph[node]){
        if(!visited[child.first]){
            /* child node can be infected only when this is infected
            and this edge can't be cutt*/
            dfs(child.first,infect&&(child.second==0));
            subtree_size[node] += subtree_size[child.first];
            /*
            only those subtrees can be saved which can be cutt and first one
            to get infected so only add those's size
            */
            if(child.second == 1 && infect){
                subtrees.push_back(subtree_size[child.first]);
            }
        }

    }
}
int main() {
    int n,k;
    cin>>n>>k;
    int a,b,c;
    memset(visited,false,sizeof(visited));
    memset(subtree_size,0,sizeof(subtree_size));
    for(int i=0;i<n-1;++i){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    // 1 will always be infected so passing true for infection...
    dfs(1,true);
    sort(subtrees.begin(),subtrees.end(),[](const int& a,const int& b){
        if(a>b){
            return true;
        }
        return false;
    });
    int saved = 0,cuts = 0;
    /*
    for(size_t i=0;i<subtrees.size();++i){
        cout<<subtrees[i]<< " ";
    }
    */
    for(size_t i=0;i<subtrees.size();++i){
        if(saved>=n-k){
            break;
        }
        saved += subtrees[i];
        cuts++;
    }
    if(saved<n-k){
        cout<<-1<<endl;
    }else{
        cout<<cuts<<endl;
    }
    return 0;
}
