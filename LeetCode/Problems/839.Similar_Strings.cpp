class Solution {
public:
    void swap(char *a,char *b){
        char tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
        return;
    }
    int numSimilarGroups(vector<string>& A) {
        vector<vector<int> > groups(A.size(),vector<int>());
        vector<bool> check(A.size(),false);
        vector<int> indexes(A.size(),false);
        for(int i=0;i<A.size()-1;i++){
            if(check[i]==true){
                continue;
            }
            for(int j=i+1;j<A.size();j++){
                int ir=0;
                int swaps = 0;
                if(A[i].length()!=A[j].length()){
                    continue;
                }
                while(ir<A[i].length()){
                    if(A[i][ir]!=A[j][ir]){
                        //indexes.push_back(ir);
                        indexes[swaps] = ir;
                        swaps++;
                        if(swaps>2)
                            break;
                    }
                    ir++;
                }
                if(swaps==2){
                    //swap(&A[j][indexes[0]],&A[j][indexes[1]]);
                    //if(A[i].compare(A[j])==0){
                    groups[i].push_back(j);
                    groups[j].push_back(i);
                    //}
                    //swap(&A[j][indexes[0]],&A[j][indexes[1]]);
                }else if(swaps==0){
                    groups[i].push_back(j);
                    groups[j].push_back(i);
                    check[j] = true;
                }
            }
        }

        int connected_components = 0;
        vector<bool> visited(A.size(),false);
        //printGraph(groups);
        for(int i=0;i<A.size();i++){
            if(!visited[i]){
                dfs(groups,i,visited);
                connected_components++;
            }
        }
       return connected_components;
    }
    void printGraph(vector<vector<int> >& groups){
        for(int i=0;i<groups.size();i++){
            for(int j=0;j<groups[i].size();j++){
                cout<<groups[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void dfs(vector<vector<int> >& groups,int i,vector<bool>& visited){
        visited[i] = true;
        for(vector<int>::iterator j=groups[i].begin();j!=groups[i].end();j++){
            if(!visited[*j]){
                dfs(groups,*j,visited);
            }
        }
        return;
    }
};
