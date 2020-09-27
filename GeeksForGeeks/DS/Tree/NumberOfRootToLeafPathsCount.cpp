/ { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void pathCounts( Node* node);

/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     pathCounts(root);
     cout<< endl;
  }
  return 0;
}
// } Driver Code Ends


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*You are required to complete below method */
bool leaf(Node* root){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL&&root->right==NULL){
        return true;
    }
    return false;
}
void count_paths(Node* root,unordered_map<int,int>& mmap,int len){
    if(root==NULL){
        return;
    }
    if(leaf(root)){
        mmap[len+1] += 1;
    }
    count_paths(root->left,mmap,len+1);
    count_paths(root->right,mmap,len+1);
}
void pathCounts(Node *root)
{
    //Your code here
    unordered_map<int,int> mmap;
    int len = 0;
    count_paths(root,mmap,len);
    vector<pair<int,int> > ans;
    for(auto it=mmap.begin();it!=mmap.end();++it){
        ans.push_back({it->first,it->second});
    }
    sort(ans.begin(),ans.end(),[](const pair<int,int>& a,const pair<int,int>& b){
    return a.first<b.first;
});
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].first<<" "<<ans[i].second<<" $";
    }
}
