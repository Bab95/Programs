#include <bits/stdc++.h>
using namespace std;
struct dsu{
    vector<int> parent,size;
    dsu(int n):parent(n),size(n,1){
        for(int i=0;i<n;++i){
            parent[i] = i;
        }
    }
    int root(int a){
        if(a==parent[a]){
            return a;
        }
        return parent[a] = root(parent[a]);
    }

    void merge(int a,int b){
        a = root(a);
        b = root(b);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            size[a] += size[b];
            parent[b] = a;
        }
    }
};

vector<int> connectedCities(int numCities,)


int segment(){


    deque<int> q(x);
    vector<int> answers;
    int i;
    for(i=0;i<x;++i){
        while(!q.empty()&&space[i]<=space[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    for(;i<space.size();++i){
        answers.push_back(space[q.front()]);
        while(!q.empty()&&q.front()<=i-x){
            q.pop_front();
        }
        while(!q.empty()&&space[i]<=space[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    int ans = INT_MIN;
    for(int i=0;i<answers.size();++i){
        ans = max(ans,answers[i]);
    }
    return ans;
}
