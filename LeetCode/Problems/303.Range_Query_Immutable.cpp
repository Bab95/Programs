class NumArray {
public:
    struct segTree{
        int data;
        int start_index;
        int end_index;
        struct segTree *left,*right;
        segTree(int d,int si,int ei):data(d),start_index(si),end_index(ei),left(NULL),right(NULL){}
    };
    struct segTree* build_segment_Tree(vector<int>& sum,int low,int high){
        if(low==high){
            return new segTree(sum[low+1]-sum[low],low,high);
        }
        else if(low<high){
            int mid = (low+high)/2;
            segTree* root = new segTree(sum[high+1]-sum[low],low,high);
            root->left = build_segment_Tree(sum,low,mid);
            root->right = build_segment_Tree(sum,mid+1,high);
            return root;
        }
        return NULL;
    }
    int query(segTree* root,int i,int j){
        if(root->start_index==i&&root->end_index==j){
            return root->data;
        }
        int mid = (root->start_index+root->end_index)/2;
        if(i>mid){
            return query(root->right,i,j);
        }else if(i<=mid&&j>mid){
            int l_sum = query(root->left,i,mid);
            int r_sum = query(root->right,mid+1,j);
            return l_sum+r_sum;
        }else if(j<=mid){
            return query(root->left,i,j);
        }
        return INT_MAX;
    }
    segTree* root = NULL;
    NumArray(vector<int>& nums) {
        vector<int> sum(nums.size()+1);
        sum[0] = 0;
        for(int i=1;i<=nums.size();++i){
            sum[i] = sum[i-1]+nums[i-1];
        }
        root = build_segment_Tree(sum,0,nums.size()-1);
    }

    int sumRange(int i, int j) {
        return query(root,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
