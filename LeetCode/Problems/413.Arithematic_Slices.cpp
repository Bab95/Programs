class Solution {
public:
    int _count(int n){
        n -= 2;
        int ans = n*(n+1)/2;
        return ans;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3){
            return 0;
        }
        int ans = 0;
        for(int i=0;i<A.size()-2;){
            int diff = A[i+1] - A[i];
            int count = 2;
            for(int j=i+2;j<A.size();++j){
                if(A[j]-A[j-1]==diff){
                    count++;
                }else{
                    break;
                }
            }
            //cout<<count<<endl;
            if(count>=3){
                ans += _count(count);
            }
            i += (count-1);
        }
        return ans;
    }
};
