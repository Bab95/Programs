class Solution {
public:
    int complement(int a){
        if(a==0){
            return 1;
        }else{
            return 0;
        }
    }
    int find(long long int n,int k){
        if(k==2){
            return 1;
        }else if(k==1){
            return 0;
        }
        if(k>n/2){
            return complement(find(n/2,k-n/2));
        }
        return find(n/2,k);
    }
    int kthGrammar(int N, int k) {
        long long n = (long long)pow(2,N-1);
        return find(n,k);
    }
};
