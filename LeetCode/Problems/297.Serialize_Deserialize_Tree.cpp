/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ans = "[,";
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp!=NULL){
                ans+=to_string(tmp->val);
                ans+=',';
            }else{
                ans+="null,";
            }
            if(tmp!=NULL){
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        ans+="]";
        //cout<<ans<<endl;
        return ans;
    }
    void print(vector<string>& ans){
        for(string s:ans){
            cout<<s<<endl;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> pos;
        vector<string> ans;
        vector<TreeNode*> nodes;
        for(int i=1;i<data.length();++i){
            if(data[i]==','){
                pos.push_back(i);
            }
        }

        for(int i=0;i<pos.size();++i){
            if(pos[i]==data.length()-2){
                break;
            }
            int first = pos[i];
            int second = pos[i+1];
            string sub = data.substr(first+1,second-first-1);
            ans.push_back(sub);
        }
        //print(ans);
       for(int i=0;i<ans.size();++i){
           if(ans[i]=="null"){
               nodes.push_back(NULL);
           }else{
               TreeNode* tmp_node = new TreeNode(stoi(ans[i]));
               nodes.push_back(tmp_node);
           }
       }
        int i = 0;
        int j = i+1;
        if(nodes[i]==NULL){
            return NULL;
        }
        while(j<nodes.size()){
            if(nodes[i]==NULL){
                i++;
                continue;
            }
            nodes[i]->left = nodes[j];
            ++j;
            nodes[i]->right = nodes[j];
            j++;
            i++;
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
