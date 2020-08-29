class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        int n = A.size();
        for(int it=n-1;it>=0;it--){
            int val = it+1;
            for(int j=0;j<=it;++j){
                if(A[j]==val){
                    if(j!=0){
                        int l = 0,r = j;
                        while(l<r){
                            swap(A[l],A[r]);
                            l++;
                            r--;
                        }
                        ans.push_back(j+1);
                    }
                    int l = 0, r = it;
                    while(l<r){
                        swap(A[l],A[r]);
                        ++l;
                        --r;
                    }
                    ans.push_back(it+1);
                    break;
                }
            }
        }
        return ans;
    }
};
