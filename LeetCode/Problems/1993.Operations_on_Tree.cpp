class LockingTree {
public:
    // false ->unlocked true -> lock 2 -> upgrade
    vector<pair<int, bool>> tree_status;
    vector<int> _tree;
    unordered_map<int,vector<int>> child;
    LockingTree(vector<int>& parent) {
        tree_status.resize(parent.size(), make_pair(-1, false));
        for (int i=0;i<parent.size();i++){
            _tree.push_back(parent[i]);
            if (child.find(parent[i]) == child.end()){
                child[parent[i]] = {};
            }
            child[parent[i]].push_back(i);
        }
    }
    bool lock(int num, int user) {
        if (tree_status[num].second) {
            return false;
            //return tree_status[num].first == user;
        }
        tree_status[num] = make_pair(user, true);
        return true;
    }

    bool unlock(int num, int user) {
        if (tree_status[num].second && tree_status[num].first == user){
            tree_status[num].second = false;
            return true;
        }
        return false;
    }
    vector<int> getchild(int num){
        if (child.find(num) == child.end()){
            return {};
        }
        return child[num];
    }
    bool dfs(int root){
        if (root == -1){
            return false;
        }
        vector<int> _child = getchild(root);
        if (_child.size() == 0){
            return false;
        }
        for (int i=0;i<_child.size();i++){
            if (tree_status[_child[i]].second){
                return true;
            }
        }
        bool result = false;
        for (int i=0;i<_child.size();i++){
            result = result || dfs(_child[i]);
        }
        return result;
    }
    void set(int root){
        if (root == -1){
            return;
        }
        vector<int> _child = getchild(root);
        if (_child.size() == 0){
            return;
        }
        for (int i=0;i<_child.size();i++){
            tree_status[_child[i]].second = false;
            set(_child[i]);
        }
    }
    bool upgrade(int num, int user) {
        if (tree_status[num].second){
            return false;
        }
        // ancestor check.......
        int parent = _tree[num];
        while (parent != -1){
            if (tree_status[parent].second){
                return false;
            }
            parent = _tree[parent];
        }
        // descendant check......
        if (dfs(num)){
            tree_status[num].second = true;
            tree_status[num].first = user;
            set(num);
            return true;
        }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
