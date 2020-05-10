class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> xarr(arr.size(),0);
        xarr[0] = arr[0];
        for(int i=1;i<arr.size();++i){
            xarr[i] = xarr[i-1]^arr[i];
        }
        int ans = 0;
        int a = 0,b = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    if(j-1==i){
                        a = arr[i];
                    }else{
                        if(i==0){
                            a = xarr[j-1];
                        }else{
                            a = xarr[j-1]^xarr[i-1];
                        }
                    }

                    b = (k>j)?xarr[k]^xarr[j-1]:arr[k];
                    if(a==b){
                        ans++;
                    }
                  }
            }
        }
        return ans;
    }
};
