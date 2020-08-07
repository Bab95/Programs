class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0;
        int current = 0;
        queue<int> zero_index;
        if(K==0){
            for(int i=0;i<A.size();++i){
                if(A[i]==0){
                    ans = max(ans,current);
                    current = 0;
                }else{
                    current++;
                }
            }
            ans = max(current,ans);
            return ans;
        }
        for(int i=0;i<A.size();++i){
            if(A[i]==0&&zero_index.size()==K){
                ans = max(current,ans);
                int first_zero = zero_index.front();
                zero_index.pop();
                current = i - first_zero;
                zero_index.push(i);
            }else if(A[i]==0&&zero_index.size()<K){
                zero_index.push(i);
                current++;
            }else{
                current++;
            }
        }
        ans = max(ans,current);
        return ans;
    }
};
/*
[1,1,1,0,0,0,1,1,1,1,0]
2
[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
3
[0,0,0,0,0,0,0,1]
4
[1,1,0,0]
0
[0,0,0,0]
0
[1,1,1,1,1,1,1,1,0,1,0,0,0,1]
8


*/
