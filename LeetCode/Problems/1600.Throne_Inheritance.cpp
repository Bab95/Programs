class ThroneInheritance {
public:
    struct node{
        bool is_alive;
        string name;
        vector<node*> children;
        node(string _name) : name(_name), is_alive(true){
            children = {};
        }
    };
    struct node *root = NULL;
    unordered_map<string, node*> family;
    ThroneInheritance(string kingName) {
        root = new node(kingName);
        family[kingName] = root;
    }

    void birth(string parentName, string childName) {
        struct node* _child = new node(childName);
        family[childName] = _child;
        family[parentName]->children.push_back(_child);
    }

    void death(string name) {
        family[name]->is_alive = false;
    }
    void dfs(struct node* root, vector<string>& inheritance_order){
        if (root == NULL){
            return;
        }
        if (root->is_alive){
            inheritance_order.push_back(root->name);
        }
        for (int i=0;i<root->children.size();i++){
            dfs(root->children[i], inheritance_order);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string> result;
        dfs(root, result);
        return result;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
