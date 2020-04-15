/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) { 
        vector<vector<int> > result;
        if(root==NULL){
            return result;
        }
        queue<Node*> q;
        q.push(root);
        //result.push_back({root->val});
        while(!q.empty()){
            vector<int> tmp;
            int n = q.size();
            for(int i=0;i<n;++i){
                Node* p = q.front();
                q.pop();
                tmp.push_back(p->val);
                for(int j=0;j<p->children.size();++j){
                    q.push(p->children[j]);
                }
            }
            if(tmp.size()!=0){
                result.push_back(tmp);
            }
        }
        return result;
    }
};