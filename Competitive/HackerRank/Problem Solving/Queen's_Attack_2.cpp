#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
bool safe(int n,int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=n){
        return true;
    }
    return false;
}
int dx[] = {-1,0,1,1,1,0,-1,-1};
int dy[] = {1,1,1,0,-1,-1,-1,0};
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    queue<pair<char,pair<int,int> > > q;
    int ans = 0;
    unordered_map<char,pair<int,int> > direction_map;

    for(int i=0;i<8;++i){
        direction_map['a'+i] = make_pair(dx[i],dy[i]);
    }
    unordered_set<pair<int,int> ,hash_pair> obstacles_map;
    for(auto it : obstacles){
        obstacles_map.insert(make_pair(it[0],it[1]));
    }
    for(int i=0;i<8;++i){
        int x = r_q + dx[i];
        int y = c_q + dy[i];
        if(safe(n, x, y)&&obstacles_map.count({x,y})==0){
            q.push({'a'+i,{x,y}});
            //cout<<"("<<x<<","<<y<<"), ";
            ans++;
        }
    }
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        char direction = it.first;
        int _x = it.second.first + direction_map[direction].first;
        int _y = it.second.second + direction_map[direction].second;
        if(safe(n, _x, _y)&&obstacles_map.find({_x,_y})==obstacles_map.end()){
            q.push({direction,{_x,_y}});
            ans++;
            //cout<<"("<<_x<<","<<_y<<"), ";
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
