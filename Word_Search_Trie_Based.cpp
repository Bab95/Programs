class Solution {
public:
    struct trieNode{
        triNode* children[26];
        bool isEnd;
        int count = 0;
        trieNode(){
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isEnd = false;
            count = 0;
        }
    };
    triNode* buildTrie(vector<string>& words){
        for(int i=0;i<words.size();i++){

        }
    }
    bool safe(vector<vector<char> >& board,vector<vector<bool> >& visited,int i,int j){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&!visited[i][j]){
            return true;
        }
        return false;
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
        vector<string> result;
        vector<vector<bool> > visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<words.size();i++){
            if(my_map.find((char)words[i][0])==my_map.end()){
                //cout<<words[i]<<" cant be found"<<endl;
                continue;
            }else{
                for(itr=my_map[words[i][0]].begin();itr!=my_map[words[i][0]].end();itr++){
                    bool res = search(visited,board,words[i],p.first,p.second,0);
                    if(res){
                        result.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return result;
    }
};
