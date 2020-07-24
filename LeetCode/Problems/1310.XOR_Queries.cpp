class Solution {
public:
    struct node{
        int data;
        struct node *left;
        struct node *right;
        int start_index;
        int end_index;
        node(int data,int start,int end):data(data),start_index(start),end_index(end),left(NULL),right(NULL){}
    };

    node* build_tree(vector<int>& arr,int low,int high){
        if(low>high){
            return NULL;
        }
        if(low==high){
            return new node(arr[low],low,high);
        }
        int mid = low + (high-low)/2;
        node* root = new node(0,low,high);
        root->left = build_tree(arr,low,mid);
        root->right = build_tree(arr,mid+1,high);
        root->data = (root->left->data)^(root->right->data);
        return root;

    }
    void inorder(node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    int query(node* root,int start,int end){
        //cout<<"("<<start<<","<<end<<")"<<endl;
        if(start>end){
            return 0;
        }
        if(root==NULL){
            return 0;
        }
        if(root->start_index==start&&root->end_index==end){
            return root->data;
        }
        int mid = root->start_index + (root->end_index-root->start_index)/2;
        if(end<=mid){
            return query(root->left,start,end);
        }else if(start>mid){
            return query(root->right,start,end);
        }else if(start<=mid&&end>mid){
            int left = query(root->left,start,mid);
            int right = query(root->right,mid+1,end);
            return left^right;
        }
        return 0;

    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        node* root = NULL;
        root = build_tree(arr,0,arr.size()-1);
        //inorder(root);
        vector<int> ans(queries.size());
        int k = 0;
        for(auto q : queries){
            ans[k++] = query(root,q[0],q[1]);
        }
        return ans;
    }
};
/*
[4,8,2,10]
[[2,3],[1,3],[0,0],[0,3]]
*/
