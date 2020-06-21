class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mmap;

        for(int i=0;i<A.size();++i){
            for(int j=0;j<B.size();++j){
                mmap[A[i]+B[j]]+=1;
            }
        }
        unordered_map<int,int> mmap2;
        for(int i=0;i<C.size();++i){
            for(int j=0;j<D.size();++j){
                mmap2[C[i]+D[j]]+=1;
            }
        }
        int ans = 0;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if(mmap2.find(-1*it->first)!=mmap2.end()){
                ans += (it->second*mmap2[-1*it->first]);
            }
        }
        return ans;
    }
};
