class Solution {
public:
    struct node{
        struct node *left;
        struct node *right;
        node():left(NULL),right(NULL){}
    };
    void insert(int num,node* root){
        node* p = root;
        for(int i=30;i>=0;i--){
            int _bit =  (num>>i)&1;
            //cout<<_bit<<endl;
            if(_bit){
                if(p->right==NULL){
                    p->right = new node();
                }
                p = p->right;
            }else{
                if(p->left==NULL){
                    p->left = new node();
                }
                p = p->left;
            }
        }
    }
    int search(int num,node* root){
        node* p = root;
        int ans = 0;
        for(int i=30;i>=0;i--){
            int _bit = (num>>i)&1;
            if(_bit){
                if(p->left!=NULL){
                    p = p->left;
                    ans = ans<<1;
                    ans = ans|1;
                }else{
                    p = p->right;
                    ans = ans<<1;
                }
            }else{
                if(p->right!=NULL){
                    p = p->right;
                    ans = ans<<1;
                    ans = ans|1;
                }else{
                    p = p->left;
                    ans = ans<<1;
                }
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        node* root = new node();
        for(int i=0;i<nums.size();++i){
            insert(nums[i],root);
        }
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            ans = max(ans,search(nums[i],root));
        }
        return ans;
    }
};
