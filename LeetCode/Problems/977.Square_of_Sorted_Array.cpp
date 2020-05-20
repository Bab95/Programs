class Solution {
public:
    int binary_search(vector<int>& arr,int start,int end){
        //cout<<"debug: "<<start<<" "<<end<<endl;
        if(start>end){
            return -1;
        }
        int mid = (start+end)/2;
        if(mid>0&&arr[mid]>0&&arr[mid-1]<=0){
            return mid;
        }
        if(arr[mid]<=0){
            return binary_search(arr,mid+1,end);
        }else if(arr[mid]>0){
            return binary_search(arr,start,mid-1);
        }
        return -1;
    }
    vector<int> sortedSquares(vector<int>& A) {
        int mid_point = binary_search(A,0,A.size()-1);
        cout<<mid_point<<endl;
        vector<int> ans;
        ans.reserve(A.size());
        if(mid_point==-1){
            if(A[A.size()-1]<=0){
                for(int i=A.size()-1;i>=0;i--){
                    ans.push_back(A[i]*A[i]);
                }
            }else{
                for(int i=0;i<A.size();++i){
                    ans.push_back(A[i]*A[i]);
                }
            }
        }else{
            int l,r;
            r = mid_point;
            l = mid_point-1;
            while(l>=0&&r<A.size()){
                if(A[l]*A[l]<A[r]*A[r]){
                    ans.push_back(A[l]*A[l]);
                    l--;
                }else{
                    ans.push_back(A[r]*A[r]);
                    r++;
                }
            }

            while(l>=0){
                ans.push_back(A[l]*A[l]);
                l--;
            }
            while(r<A.size()){
                ans.push_back(A[r]*A[r]);
                r++;
            }
        }
        return ans;
    }
};
