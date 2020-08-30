class Solution {
public:
    int find_set(vector<int>& parent,int v){
        if(v==parent[v]){
            return v;
        }
        return parent[v] = find_set(parent,parent[v]); //path compression......
    }

    int largestComponentSize(vector<int>& A) {
        map<int,vector<int> > mmap;
        int n = A.size();
        vector<int> parent(n);
        vector<int> size(n,1);
        for(int i=0;i<n;++i){
            parent[i] = i;
        }

        int x;
        for(int i=0;i<n;++i){
            x = A[i];
            bool flag = false;
            while(x%2==0){
                x /= 2;
                flag = true;
            }
            if(flag){
                mmap[2].push_back(i);
            }
            for(int k=3;k<=sqrt(x);k+=2){
                flag = false;
                while(x%k==0){
                    x = x/k;
                    flag = true;
                }
                if(flag){
                    mmap[k].push_back(i);
                }
            }
            if(x>2){
                mmap[x].push_back(i);
            }
        }
        int ans = 1;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            for(int k=0;k<it->second.size()-1;++k){
                int a = find_set(parent,it->second[k]);
                int b = find_set(parent,it->second[k+1]);
                if(a!=b){
                    if(size[a]<size[b]){
                        swap(a,b);
                    }
                    parent[b] = a;
                    size[a] += size[b];
                    ans = max(ans,size[a]);
                }
            }
        }
        return ans;
    }
};
