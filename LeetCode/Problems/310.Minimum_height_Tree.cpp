class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	    vector<unordered_set<int> > graph(n, unordered_set<int>());
	    for (auto it : edges) {
		    graph[it[0]].insert(it[1]);
		    graph[it[1]].insert(it[0]);
	    }
	    vector<int> leaves;
	    for (int i = 0;i < n;++i) {
		    if (graph[i].size() == 1) {
			    //its a leaf node.....
			    leaves.push_back(i);
		    }
	    }
	    while (n > 2) {
		    n -= leaves.size();
		    vector<int> new_leaves;
		    for (auto node : leaves) {
			    auto parent_itr = graph[node].begin();
			    int parent = *parent_itr;
			    graph[parent].erase(node);
			    if (graph[parent].size() == 1) {
				    new_leaves.push_back(parent);
			    }

		    }
		    leaves = new_leaves;
	    }
	    if (leaves.size() == 0) {
		    return { 0 };
	    }
	    return leaves;
    }
};
