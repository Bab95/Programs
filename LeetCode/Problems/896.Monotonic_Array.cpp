class Solution {
public:
    int sign(int a){
        if(a<0){
            return -1;
        }
        else if(a>0){
            return 1;
        }
        return 0;
    }
    bool isMonotonic(vector<int>& A) {
        if(A.size()<=2){
            return true;
        }
        int diff = A[1] - A[0];
        int index = 2;
        if(diff==0){

            while(diff==0&&index<A.size()){
                diff = A[index]-A[index-1];
                index++;
            }
            if(diff==0&&index==A.size()){
                return true;
            }
        }
        for(int i=index;i<A.size();++i){
            if(A[i]-A[i-1]==0){
                continue;
            }else if(sign(A[i]-A[i-1])!=sign(diff)){
                return false;
            }
        }
        return true;
    }
};
