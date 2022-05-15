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
    int bfs(int start, int end, vector<vector<int>>& graph){
        int n = graph.size();
        // vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int length = 1;
        while (!q.empty()){
            int qn = q.size();
            while (qn--){
                int current = q.front();
                q.pop();

                for (int i=0;i<graph[current].size();i++){
                    int child  = graph[current][i];
                    if (child == end){
                        return length + 1;
                    }
                    if (!visited[child]){
                        q.push(child);
                        visited[child] = true;
                    }
                }
            }
            length++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> nodes;
        for (int i=0;i<wordList.size();i++){
            nodes[wordList[i]] = i;
        }
        if (nodes.find(beginWord) == nodes.end()){
            nodes[beginWord] = wordList.size();
            wordList.push_back(beginWord);
        }
        if (nodes.find(endWord) == nodes.end()){
            return 0;
        }
        if (isconnection(beginWord, endWord)){
            return 2;
        }
        vector<vector<int>> graph(nodes.size(), vector<int>());
        for (int i=0;i<wordList.size()-1;i++){
            for (int j=i+1;j<wordList.size();j++){
                if (isconnection(wordList[i], wordList[j])){
                    graph[nodes[wordList[i]]].push_back(nodes[wordList[j]]);
                    graph[nodes[wordList[j]]].push_back(nodes[wordList[i]]);
                }
            }
        }
        int a = nodes[beginWord];
        int b = nodes[endWord];
        // cout << a << " " << b <<endl;
        int ans = bfs(a, b, graph);
        return ans;
    }
};
