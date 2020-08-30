/*
This data structure provides following capabilities....
Given several elements each of which is a separate set. DSU will combine any two sets
and will be able to tell in which set a specific element is.

3 basic operations.

make_set(v):- Create a new set consisting of the new element v.

union_set(a,b):-merge two specified sets the one in which a is located and second in which
b is located.

find_set(v):- returns the leader/representative or root of the set.

*/


#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int parent[MAX];
int size[MAX];
int rank[MAX];
bool bipartite[MAX];
////////////Naive Implementation..........///////////////
void make_set(int v){
    parent[v] = v;
}
int find_set(int v){
    if(parent[v]==v){
        return v;
    }
    return find_set(parent[v]);
}
void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        parent[b] = a;
        //means b a is root now b is a's children......
    }
}
///////Path Compression Optimization.......//////////////
/*
If find_set if called for some vertex v we have already found leader of all the vertices
between vertex v and leader(root) p. 
So make p as parent of all these vertices.
*/
int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find_set(parent[v]);
}
/*
this will first simply find the root of the set and while unwinding the stack
root will be assigned the parent of all these vertices.
*/

//////////Union by size/rank......////////////
/*
It is possible that tree may become a chain of length n. So we will have to choose the
root wisely while taking union of the two sets.
Attach the tree with lower size to the tree with bigger size....
*/
void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}
void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

////Rank based implementation............
void make_set(int v){
    parent[v] = v;
    rank[v] = 0;
}
void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(rank[a]<rank[b]){
            swap(a,b);
        }
        parent[b] = a;
        if(rank[a]==rank[b]){
            rank[a]++;
        } 
    }
}


//compress jumps along a segment or Painting subarrays offline.
/*
Offline means queries will be given in advance......

Consider queries in reverse order. This way when execute a query we will have to paint
exactly unpainted cells in subarray[l..r].All other cells already contain their final color.
Find left most unpainted cell in query repaint it and move to the next unpainted cell to the
right.

We cannot use union by rank/size because its important who becomes leader after merge..

*/
void func(){
    for(int i=0;i<=L;++i){
        make_set(i);
    }

    for(int i=m-1;i>=0;i--){
        int l = query[i].l;
        int r = query[i].r;
        int c = query[i].c;
        for(int v = find_set(l);v<=r;v=find_set(v)){
            answer[v] = c;
            parent[v] = v + 1;
        }
    }
}


/////Support distance up to the representative.........
/*
Maintain the distance between a vertex and its representative of its set i.e. path length
in tree from current node to the root node.
It is possible to do path compression if distance to parent is stored as an additional
information for each node.

In implementation array of pairs of parent and the distance to it will be kept. 
*/
//////////////IMPLEMENTATION///////////
void make_set(int v){
    parent[v] = make_pair(v,0);
    rank[v] = 0;
}
pair<int,int> find_set(int v){
    if(v!=parent[v].first){
        int len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}
void union_sets(int a,int b){
    a = find_set(a).first;
    b = find_set(b).first;
    if(a!=b){
        if(rank[a]<rank[b]){
            swap(a,b);
        }
        parent[b] = make_pair(a,1);//b's distance to root is 1......
        if(rank[a]==rank[b]){
            rank[a]++;
        }
    }
}

////////Suppor the parity of the path length /Checking the bipartiteness online.....
/*
The unusual requirement of storing the path parity comes up in the following taks:
Initially we are given an empty graph, edges can be added to it, and we have to answer
queries of the form if connected component containing this vertex bipartite?

Solution:- Make a DSU for storing of the components and store the parity of the path up
to the leader for each vertex. If the ends of the edge lies in the same connected component
and have the same parity length to the leader then adding this edge will produce a cycle of 
odd length and component will loose its bipartite property.

If we add edge(a,b) that connects two components into one then when one tree is attached to 
another parity need to be adjusted.
parity of B 
x = parity of a
y = parity of b
t = new parity of B(leader of b).
t = x (XOR) y (XOR) 1
  
*/
void make_set(int v){
    parent[v] = make_pair(v,0);
    rank[v] = 0;
    bipartitie[v] = true;
}
pair<int,int> find_set(int v){
    if(v!=parent[v].first){
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}
void add_edge(int a,int b){
    pair<int,int> pa = find_set(a);
    a = pa.first(a);
    int x = pa.second;
    pair<int,int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;
    if(a==b){
        if(x==y){
            bipartite[a] = true;
        }
    }else{
        if(rank[a]<rank[b]){
            swap(a,b);
        }
        parent[b] = make_pair(a,x^y^1);
        bipartite[a] &= bipartite[b];
        if(rank[a]==rank[b]){
            rank[a]++;
        }
    }
}
bool isbipartite(int v){
    return bipartite[find_set(v).first];
}
int main(){
    memset(parent,-1,sizeof(parent));
    memset(rank,0,sizeof(rank));
    memset(size,0,sizeof(size));
}