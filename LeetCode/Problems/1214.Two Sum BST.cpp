class Solution{
public:
  void storeBst(TreeNode* root,vector<int>& arr){
    if(root==NULL){
      return;
    }
    storeBst(root->left,arr);
    arr.push_back(root->val);
    storeBst(root->right,arr);
  }
  bool twoSumBSTs(TreeNode* root1,TreeNode* root2,int target){
      vector<int> arr1;
      vector<int> arr2;
      storeBst(root1,arr1);
      storeBst(root2,arr2);
      int l = 0;
      int r = arr2.size()-1;
      while(l<arr1.size()&&r>=0){
        if(arr1[l]+arr2[r]==target){
          return true;
        }else if(arr1[l]+arr2[r]<target){
          l++;
        }else{
          r--;
        }
      }
      return false;
  }
};

class Solution2{
  bool twoSumBSTs(TreeNode* root1,TreeNode* root2,int target){
      stack<TreeNode*> s1;
      stack<TreeNode*> s2;
      TreeNode* current1 = root1;
      TreeNode* current2 = root2;
      while(current1||current2||s1.size()||s2.size()){
        if(current1){
          //tree one left side inorder.....
          s1.push(current1);
          current1 = current1->left;
        }else if(current2){
          // tree 2 right side reverse inorder...
          s2.push(current2);
          current2 = current2->right;
        }else if(s1.size()&&S2.size()){
          int sum = s1.top()->val+s2.top()->val;
          if(sum==target){
            return true;
          }else if(sum<target){
            // move from left....
            current1 = s1.top()->right;
            s1.pop();
            current2 = NULL;
          }else if(sum>target){
            current2 = s2.top()->left;
            s2.pop();
            current1 = NULL;
          }
        }else{
          break;
        }
      }
      return false;
  }
};
