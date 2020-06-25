class Solution {
public:
    bool oneword(string& s1, string& s2) {
	    int i = 0;
	    int count = 0;
	    while (i<s1.length()) {
		    if (s1[i] != s2[i]&&count>0) {
			    return false;
		    }else if(s1[i]!=s2[i]){
                count++;
            }
		    ++i;
	    }
	    if (count!=1){
		    return false;
	    }
	    return true;
    }
    void bfs(queue<int>& q, vector<int>& parent, vector<bool>& visited, vector<vector<int> >& graph,int end_node) {
	    int current = q.front();
	    q.pop();
	    for (int i = 0;i<graph[current].size();++i) {
		    int child = graph[current][i];
            if(child==end_node){
            //if i am currently at required...... then what shall be done.......
                return;
            }
		    if (!visited[child]) {
			    parent[child] = current;
			    visited[child] = true;
			    q.push(child);
		    }
	    }
    }

    int getintersection(vector<bool>& visited_src, vector<bool>& visited_dst) {
	    for (int i = 0;i<visited_src.size();++i) {
		    if (visited_src[i] && visited_dst[i]) {
			    return i;
		    }
	    }
	    return -1;
    }
    int getpathLength(vector<int>& parent_src, vector<int>& parent_dst, int start_node, int end_node, int intersection_node) {
	    int i = intersection_node;
	    int count = 1;
	    /*vector<int> path;
	    path.push_back(i);*/
	    while (i != start_node) {
		    //path.push_back(parent_src[i]);
		    i = parent_src[i];
		    count++;
	    }
	    i = intersection_node;
	    //reverse(path.begin(), path.end());
	    while (i != end_node) {
		    //path.push_back(parent_dst[i]);
		    i = parent_dst[i];
		    count++;
	    }
        /*
	    for (int i = 0;i<path.size();++i) {
		    cout << path[i] << " ";
	    }
	    cout << endl;*/
	    return count;
    }
    int bidirectional_search(int start_node, int end_node, vector<vector<int> >& graph) {
	    int n = graph.size();
	    vector<int> parent_src(n, -1);
	    vector<int> parent_dst(n, -1);
	    queue<int> s_q;
	    queue<int> d_q;
	    int intersection_node = -1;
	    vector<bool> visited_src(n, false);
	    vector<bool> visited_dst(n, false);

	    s_q.push(start_node);
	    d_q.push(end_node);
	    visited_src[start_node] = true;
	    visited_dst[end_node] = true;
	    while (!s_q.empty() && !d_q.empty()) {

		    bfs(s_q, parent_src, visited_src, graph,end_node);
		    bfs(d_q, parent_dst, visited_dst, graph,start_node);

		    intersection_node = getintersection(visited_src, visited_dst);
		    if (intersection_node != -1) {
			    return getpathLength(parent_src, parent_dst, start_node, end_node, intersection_node);
		    }
	    }
	    return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	    unordered_map<string, int> mmap;
	    bool flag = false;
	    for (int i = 0;i<wordList.size();++i) {
		    if (wordList[i].compare(beginWord)==0) {
			    flag = true;
			    break;
		    }
	    }
	    if (flag==false) {
		    wordList.push_back(beginWord);
	    }
	    for (int i = 0;i<wordList.size();++i) {
	    	mmap[wordList[i]] = i;
	    }
	    if (mmap.find(endWord) == mmap.end()) {
		    return 0;
	    }
        if(oneword(beginWord,endWord)){
            return 2;
        }
	    vector<vector<int> > graph(mmap.size(), vector<int>());
	    for (int i = 0;i<wordList.size() - 1;++i) {
		    for (int j = i + 1;j<wordList.size();++j) {
			    if (oneword(wordList[i], wordList[j])) {
				    int ind_a = mmap[wordList[i]];
				    int ind_b = mmap[wordList[j]];
				    graph[ind_a].push_back(ind_b);
				    graph[ind_b].push_back(ind_a);
			    }
		    }
	    }
        /*
	    for (int i = 0;i < graph.size();++i) {
		    cout << i << " :";
		    for (int j = 0;j < graph[i].size();++j) {
			    cout << graph[i][j] << " ";
		    }
		    cout << endl;
	    }
        */
	    int start_node = mmap[beginWord];
	    int end_node = mmap[endWord];
	    int ans = bidirectional_search(start_node, end_node, graph);
	    return ans;
    }
};
