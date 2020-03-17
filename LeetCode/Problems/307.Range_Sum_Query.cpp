class NumArray {
public:
    struct node{
        int sum;
        int start,end;
        struct node *left,*right;
        node(int s,int i,int e): sum(s),start(i),end(e),left(NULL),right(NULL){}
    };
    struct node* Root;
    vector<int> ranged_sum;
    vector<int> numbers;
    NumArray(vector<int>& nums) {
        numbers.insert(numbers.end(),nums.begin(),nums.end());
        ranged_sum.push_back(0);
        for(int i=1;i<=nums.size();i++){
            int t_sum = ranged_sum[i-1] + nums[i-1];
            ranged_sum.push_back(t_sum);
        }
        Root = Build_Segment_Tree(nums,ranged_sum,0,nums.size()-1);
        /*inorder(Root);
        cout<<endl;*/
    }

    struct node* Build_Segment_Tree(vector<int>& nums,vector<int>& ranged_sum,int start,int end){
        if(start==end){
            struct node* new_node = new node(nums[start],start,end);
            return new_node;
        }
        if(start<end){
            int data = ranged_sum[end+1]-ranged_sum[start];
            struct node* new_node = new node(data,start,end);
            int mid = (start+end)/2;
            new_node->left = Build_Segment_Tree(nums,ranged_sum,start,mid);
            new_node->right = Build_Segment_Tree(nums,ranged_sum,mid+1,end);
            return new_node;
        }
        return NULL;
    }
    void update_segment_Tree(struct node* root,int i,int val){
        if(root==NULL){
            return;
        }
        if(root->start==i&&root->end==i){
            root->sum = root->sum - numbers[i] + val;
            return;
        }
        root->sum = root->sum - numbers[i] + val;
        int mid = (root->start+root->end)/2;
        if(i<=mid){
            update_segment_Tree(root->left,i,val);
        }else if(i>mid){
            update_segment_Tree(root->right,i,val);
        }

    }
    void inorder(struct node *root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->sum<<" ";
        inorder(root->right);
    }

    void update(int i, int val) {

        update_segment_Tree(Root,i,val);
        numbers[i] = val;
        //inorder(Root);
    }
    int getSum(struct node *root,int start,int end){
        if(start==root->start&&end==root->end){
            return root->sum;
        }
        int mid = (root->start + root->end)/2;
        if(start>mid){
            return getSum(root->right,start,end);
        }else if(mid>=start&&mid<end){
            int left_sum = getSum(root->left,start,mid);
            int right_sum = getSum(root->right,mid+1,end);
            return (left_sum + right_sum);
        }
        else if(end<=mid){
            return getSum(root->left,start,end);
        }
        return INT_MAX;
    }
    int sumRange(int i, int j) {

        int required_Sum = INT_MAX;
        if(i<j){
            required_Sum = getSum(Root,i,j);
        }else{
            required_Sum = getSum(Root,j,i);
        }
        return required_Sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
