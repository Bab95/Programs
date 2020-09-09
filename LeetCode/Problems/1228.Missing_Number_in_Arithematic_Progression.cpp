class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int curr = -1;
        int prev = -1;
        int next = -1;
        prev = arr[1]-arr[0];
        for(int i=2;i<arr.size();++i){
            int curr = arr[i]-arr[i-1];
            if(prev==curr){
                continue;
            }else if(i<arr.size()-1){
                next = arr[i+1]-arr[i];
                if(next==prev){
                    return arr[i-1]+curr/2;
                }else{
                    return arr[i-1]-curr;
                }
            }else{
                if(curr==2*prev){
                    return arr[i]-prev;
                }else if(prev==2*curr){
                    return arr[i-1]-curr;
                }
            }
        }
        return arr[arr.size()-1];
    }
};
