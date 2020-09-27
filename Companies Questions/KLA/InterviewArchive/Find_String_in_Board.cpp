#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
int dx[] = {1,-1,1,-1,-1,1,0,0};
int dy[] = {0,0,1,-1,1,-1,1,-1};
bool safe(pair<int,int>& p,vector<vector<char>>& mat){
    if(p.first>=0&&p.first<mat.size()&&p.second>=0&&p.second<mat[0].size()){
        return true;
    }
    return false;
}
bool bfs(vector<vector<char>>& mat,int i,int j,string& pattern,int dir,unordered_map<int,pair<int,int>>& direction){
    queue<pair<int,int> > q;
    q.push({i,j});
    int index = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        if(!safe(p,mat)){
            return false;
        }
        if(mat[p.first][p.second]!=pattern[index]){
            return false;
        }
        index += 1;
        if(index==pattern.length()){
            return true;
        }
        p.first += direction[dir].first;
        p.second += direction[dir].second;
        q.push(p);
    }
    return false;
}
void solve(){
    int m,n;
    cin>>m>>n;
    fflush(stdin);
    vector<vector<char> > mat(m,vector<char>(n));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>mat[i][j];
        }
    }
    string pattern;
    cin>>pattern;
    int ans = 0;
    vector<vector<bool> > visited(m,vector<bool>(n,false));
    set<pair<int,int> > res;
    unordered_map<int,pair<int,int> > direction;
    for(int i=0;i<8;++i){
        direction[i] = make_pair(dx[i],dy[i]);
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(mat[i][j]==pattern[0]){
                for(int dir=0;dir<8;++dir){
                    if(bfs(mat,i,j,pattern,dir,direction)){
                        res.insert({i,j});
                    }
                }
            }
        }
    }
    if(res.size()==0){
        cout<<"-1"<<endl;
        return;
    }
    for(set<pair<int,int>>::iterator itr=res.begin();itr!=res.end();++itr){
        cout<<itr->first<<" "<<itr->second<<", ";
    }
    cout<<endl;
}
int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
 4
4 7
m k i k b m j b c h f e i b a g h b l i m j c f c n h k
mm
3 9
d e h d d d g d n i d n n i a j h g i j f g d c o k n
dc
8 15
i m g d j l e m k h e k c e l j o l h i b d g d d e h o f g k f l i i f f f c h m o c o d f j c i b k k l j n h f n g k e i a h b j n n g h f d g o d b l e d f f g a j h f b m d o a a h h h i b m h o m e d d e n f a c a m o n m i f k b k n
k
11 12
a k g j c o m d o o i e d b i l k o o e l g o g j n a o j k k k f b l a h i d o o d d j e e g h k m l h e c f f a f m j h h l n b h f i h i h o l d i a o o h j m k b i m n f e k c g d c c i d c n d b g l a j g j b f a j o e l i m j g k n j m e m g o f j i d n j b
kk
 */