class Solution {
public:
    struct trienode{
        bool isend;
        trienode* child[26];
        trienode(bool end):isend(end){
            for(int i=0;i<26;++i){
                child[i] = NULL;
            }
        }
    };
    void insert(trienode* root,string& str){
        struct trienode* pcrawl = root;
        for(auto c : str){
            int index = (int)c-'a';
            if(pcrawl->child[index]==NULL){
                pcrawl->child[index] = new trienode(false);
            }
            pcrawl = pcrawl->child[index];
        }
        pcrawl->isend = true;
    }

    void construct_trie(trienode** root_p,vector<string>& words){
        trienode* root = new trienode(false);
        for(int i=0;i<words.size();++i){
            insert(root,words[i]);
        }
        *root_p = root;
    }
    bool safe(vector<vector<char> >& board,vector<vector<bool> >& visited,int i,int j){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&!visited[i][j]){
            return true;
        }
        return false;
    }


    void search(trienode* pcrawl,vector<vector<bool> >& visited,vector<vector<char> >& board,pair<int,int> pos,string& current,set<string>& result){
        visited[pos.first][pos.second] = true;
        if(pcrawl==NULL){
            return;
        }
        if(pcrawl!=NULL&&pcrawl->isend==true){
            result.insert(current);
        }
        static int neighbour[] = {0,1,0,-1,0};
        for(int i=0;i<4;i++){
            int x = pos.first+neighbour[i];
            int y = pos.second+neighbour[i+1];
            if(safe(board,visited,x,y)&&pcrawl->child[(int)board[x][y]-'a']!=NULL){
                current.push_back(board[x][y]);
                pair<int,int> newpos = make_pair(x,y);
                search(pcrawl->child[(int)board[x][y]-'a'],visited,board,newpos,current,result);
            }
        }
        if(current.length()>0)
            current.pop_back();
        visited[pos.first][pos.second] = false;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trienode* root = NULL;

        construct_trie(&root,words);

        unordered_map<char,vector<pair<int,int> > > mmap;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                mmap[board[i][j]-'a'].push_back(make_pair(i,j));
            }
        }
        vector<vector<bool> > visited(board.size(),vector<bool>(board[0].size(),false));
        set<string> result;
        for(int i=0;i<26;++i){
            trienode* pcrawl = root->child[i];
            if(pcrawl!=NULL){
                for(auto it : mmap[i]){
                    string current;
                    pair<int,int> p = it;
                    current.push_back(board[p.first][p.second]);
                    search(pcrawl,visited,board,p,current,result);
                }
            }
        }
        vector<string> ans;
        for(auto str : result){
            ans.push_back(str);
        }
        return ans;
    }
};

/*
Backtracking solution[Slow]
class Solution {
public:
    bool safe(vector<vector<char> >& board,vector<vector<bool> >& visited,int i,int j){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&!visited[i][j]){
            return true;
        }
        return false;
    }
    void reinitialize_visited(vector<vector<bool> >& visited,bool value){
        for(int i=0;i<visited.size();i++){
            for(int j=0;j<visited[0].size();j++){
                visited[i][j] = false;
            }
        }
    }
    void print(vector<vector<bool> >& visited){
        for(int i=0;i<visited.size();i++){
            for(int j=0;j<visited[0].size();j++){
                //cout<<visited[i][j]<<" ";
                if(visited[i][j]){
                    cout<<"T"<<" ";
                }else{
                    cout<<"F"<<" ";
                }
            }
            cout<<endl;
        }
    }
    bool search(vector<vector<bool> >& visited,vector<vector<char> >& board,string& word,int s_i,int s_j,int w){
        visited[s_i][s_j] = true;
        if(w==word.length()-1&&board[s_i][s_j]==word[w]){
            visited[s_i][s_j] = false;
            return true;
        }
        static int neighbour[] = {0,1,0,-1,0};
        for(int i=0;i<4;i++){
            if(safe(board,visited,s_i+neighbour[i],s_j+neighbour[i+1])&&board[s_i+neighbour[i]][s_j+neighbour[i+1]]==word[w+1]){
                if(search(visited,board,word,s_i+neighbour[i],s_j+neighbour[i+1],w+1)){
                    visited[s_i][s_j] = false;
                    return true;
                }

            }
        }
        visited[s_i][s_j] = false;
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<char,vector<pair<int,int> > > my_map;
        vector<pair<int,int> >::iterator itr;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                my_map[board[i][j]].push_back(make_pair(i,j));
            }
        }
       unordered_map<char,vector<pair<int,int> > >::iterator it;
        for(it=my_map.begin();it!=my_map.end();it++){
            cout<<it->first<<" :";
            for(itr=it->second.begin();itr!=it->second.end();itr++){
                cout<<"("<<itr->first<<", "<<itr->second<<"), ";
            }
            cout<<endl;
        }
        vector<string> result;
        vector<vector<bool> > visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<words.size();i++){
            if(my_map.find((char)words[i][0])==my_map.end()){
                cout<<words[i]<<" cant be found"<<endl;
                continue;
            }else{
                for(itr=my_map[words[i][0]].begin();itr!=my_map[words[i][0]].end();itr++){
                    pair<int,int> p = *itr;
                    //reinitialize_visited(visited,false);
                    cout<<"before search start"<<endl;
                    print(visited);
                    bool res = search(visited,board,words[i],p.first,p.second,0);
                    if(res){
                        cout<<p.first<<" "<<p.second<<endl;
                        cout<<"after search ends"<<endl;
                        print(visited);
                        //cout<<endl;
                        result.push_back(words[i]);
                        break;
                    }
                    cout<<"after search ends"<<endl;
                    print(visited);

                }
            }
        }
        return result;
    }
};
*/
