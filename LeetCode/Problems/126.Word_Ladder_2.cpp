class Solution {
public:
    bool isconnection(string& a, string& b){
        if (a.length() != b.length()){
            return false;
        }
        int i = 0;
        int count = 0;
        while (i < a.length() && count <= 1){
            if (a[i] != b[i]){
                count++;
            }
            i++;
        }
        return (count == 1);
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> nodes;
        for (int i=0;i<wordList.size();i++){
            nodes[wordList[i]] = i;
        }
        if (nodes.find(beginWord) == nodes.end()){
            nodes[beginWord] = wordList.size();
            wordList.push_back(beginWord);
        }
        if (nodes.find(endWord) == nodes.end()){
            return {};
        }
        /*
        if (isconnection(beginWord, endWord)){
            return ;
        }*/
        vector<vector<int>> graph(nodes.size(), vector<int>());
        for (int i=0;i<wordList.size()-1;i++){
            for (int j=i+1;j<wordList.size();j++){
                if (isconnection(wordList[i], wordList[j])){
                    graph[nodes[wordList[i]]].push_back(nodes[wordList[j]]);
                    graph[nodes[wordList[j]]].push_back(nodes[wordList[i]]);
                }
            }
        }
        unordered_map<int, string> reverse_nodes;

        for (auto it = nodes.begin();it!=nodes.end();it++){
            reverse_nodes[it->second] = it->first;
        }

        int a = nodes[beginWord];
        int b = nodes[endWord];
        int n = graph.size();
        vector<vector<int>> parent(n, vector<int>());
        vector<int> dist(n, 10000);
        queue<int> q;
        dist[a] = 0;
        parent[a] = {-1};
        q.push(a);
        while (!q.empty()){
            int current = q.front();
            q.pop();
            for (int i=0;i<graph[current].size();i++){
                int child = graph[current][i];
                if (dist[child] > dist[current] + 1){
                    dist[child] = dist[current] + 1;
                    q.push(child);
                    parent[child].clear();
                    parent[child].push_back(current);
                }else if (dist[child] == dist[current] + 1){
                    parent[child].push_back(current);
                }
            }
        }
        vector<vector<string>> paths;
        vector<string> current_path;
        current_path.push_back(endWord);
        get_paths(paths, reverse_nodes, parent, b, current_path);
        return paths;
    }
    void get_paths(vector<vector<string>>& paths, unordered_map<int,string>& nodes, vector<vector<int>>& parents, int start, vector<string>& current_path){
        if (start == -1){
            // for -1 => empty string has been pushed.....
            string str = current_path.back();
            current_path.pop_back();
            reverse(current_path.begin(), current_path.end());
            paths.push_back(current_path);
            reverse(current_path.begin(), current_path.end());
            current_path.push_back(str);
            return;
        }

        for (int i=0;i<parents[start].size();i++){
            int u = parents[start][i];
            current_path.push_back(nodes[u]);
            get_paths(paths, nodes, parents, u, current_path);
            current_path.pop_back();
        }
    }
};
