class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3){
            return false;
        }
        bool increasing = true;
        if(arr[1]<arr[0]){
            return false;
        }
        for(int i=1;i<arr.size();){
            if(increasing){
                if(arr[i]>arr[i-1]){
                    i++;
                    continue;
                }else{
                    increasing = false;
                }
            }else{
                if(arr[i]<arr[i-1]){
                    i++;
                    continue;
                }else{
                    return false;
                }
            }
        }
        if(increasing){
            return false;
        }
        return true;
    }
};
