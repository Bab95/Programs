class Solution {
public:
    struct node{
        int val;
        int row;
        int col;
        node(int v,int r,int c):val(v),row(r),col(c){}  
    };
    struct comparator{
        bool operator()(struct node const& s1,struct node const& s2){
            return s1.val>s2.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node,vector<node>,comparator> pq;
        struct node nnode(0,0,0);
        for(int i=0;i<matrix.size();i++){
            nnode.val = matrix[i][0];
            nnode.row = i;
            nnode.col = 0;
            pq.push(nnode);
        }
        int i = 0;
        while(!pq.empty()&&i<k-1){
            i++;
            nnode = pq.top();
            //cout<<nnode.val<<" "<<nnode.row<<" "<<nnode.col<<endl;
            pq.pop();
            int col = nnode.col;
            if(col<matrix[0].size()-1){
                nnode.val = matrix[nnode.row][nnode.col+1];
                nnode.row = nnode.row;
                nnode.col = nnode.col + 1;
                pq.push(nnode);
            }
        }
        int ans = pq.top().val;
        //cout<<ans<<endl;
        return ans;
    }
};