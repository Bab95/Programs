#include <iostream>

#include <vector>

using namespace std;

vector<vector<int> > graph;

void dfs(vector<bool> &visited,int *count,int i){

    vector<int>::iterator itr;

    *count = *count+1;

    visited[i] = true;

    for(itr=graph[i].begin();itr!=graph[i].end();itr++){

        if(!visited[*itr]){

            dfs(visited,count,*itr);

        }

    }

}

long long int costcalculator(int count,int clib,int croad){

    long long int cost = 0;

    if(clib>croad){

        cost = clib+croad*(count-1);

    }else{

        cost = clib*count;

    }

return cost;

}

int main(int argc, char *argv[]) {

    int n,m,clib,croad,q;

    cin>>q;

    while(q--){
        graph.clear();
        cin>>n>>m>>clib>>croad;

        vector<int> tmp;

        for(int i=0;i<=n;i++){

            graph.push_back(tmp);

        }

        int a,b;

        for(int i=0;i<m;i++){

            cin>>a>>b;

            graph[a].push_back(b);

            graph[b].push_back(a);

        }

        vector<bool> visited(n+1,false);

        int count = 0;

        long long int total = 0;

        for(int i=1;i<=n;i++){

            count = 0;

            if(!visited[i]){

                dfs(visited,&count,i);

                    total+=costcalculator(count, clib, croad);

            }

        }

        cout<<total<<endl;

    }
    return 0;
}
