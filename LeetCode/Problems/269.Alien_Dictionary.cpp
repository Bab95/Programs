class Solution {
public:
    void debugGraph(vector<vector<int> >& graph){
        cout<<"--------printing graph-----"<<endl;
        for(int i=0;i<graph.size();++i){
            for(int j=0;j<graph[0].size();++j){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    string alienOrder(vector<string>& words) {
        vector<vector<int> > graph(26,vector<int>(26,0));
        unordered_map<int,int> indegree;
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words[i].length();++j){
                indegree[words[i][j]-'a'] = 0;
            }
        }
        for(int i=0;i<words.size()-1;++i){
            string s1 = words[i];
            string s2 = words[i+1];

            if(s1.length()>s2.length()&&s1.find(s2,0)==0){
                //second string can't be substring of first string as they are lexicographically sorted.....
                return "";
            }
            int k = 0;
            while(k<s1.length()&&k<s2.length()&&s1[k]==s2[k]){
                ++k;
            }
            if(k!=s1.length()&&k!=s2.length()){
                if(graph[s1[k]-'a'][s2[k]-'a']==0){
                    indegree[s2[k]-'a']++;
                    graph[s1[k]-'a'][s2[k]-'a'] = 1;
               }
            }
        }
        //debugGraph(graph);
        //vector<bool> visited(26,false);
        int visit_count = 0;
        queue<int> q;
        string ans;
        for(auto it=indegree.begin();it!=indegree.end();++it){
            if(it->second==0){
                q.push(it->first);
                //cout<<(char)(it->first+'a')<<endl;
                //ans.push_back(it->first+'a');
            }
        }
        cout<<endl;
        while(!q.empty()){
            int tmp = q.front();
            //cout<<"popping: "<<(char)(tmp+'a')<<endl;
            q.pop();
            visit_count++;
            ans.push_back(tmp+'a');
            for(int i=0;i<26;++i){
                if(graph[tmp][i]==1){
                    if(indegree[i]>0){
                        indegree[i]--;
                        if(indegree[i]==0){
                            //cout<<"pushing: "<<(char)(i+'a')<<endl;
                            q.push(i);
                        }
                    }
                }

            }
        }
        if(ans.length()!=indegree.size()){
            //cout<<"debug :"<<endl;
            //cout<<ans<<endl;
            return "";
        }
        return ans;
    }
};
