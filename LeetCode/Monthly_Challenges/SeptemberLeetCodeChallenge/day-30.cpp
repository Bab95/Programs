class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;++i){
            if(arr[i]==i+1){
                arr[i] = INT_MIN;
                continue;
            }else if(arr[i]<=0||arr[i]==INT_MIN||arr[i]>n){
                continue;
            }else if(arr[i]>0&&arr[i]<=n){
                if(arr[arr[i]-1]==INT_MIN){
                    continue;
                }else{
                    int index = arr[i];
                    while(index>0&&index<=n){
                        int next = arr[index-1];
                        arr[index-1] = INT_MIN;
                        index = next;
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            if(arr[i]!=INT_MIN){
                return i+1;
            }
        }
        return n+1;
    }
};
