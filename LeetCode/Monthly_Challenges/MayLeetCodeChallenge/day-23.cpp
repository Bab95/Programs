class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& arr,vector<vector<int>>& brr) {
        if(arr.size()==0||brr.size()==0){
            return {};
        }
        int i = 0;
        int j = 0;
        vector<vector<int> > result;
        while(i<arr.size()&&j<brr.size()){
            if(arr[i][1]<brr[j][0]){
                //no intersection....
                i++;
            }else if(brr[j][1]<arr[i][0]){
                ++j;
            }else{
                vector<int> tmp(2,0);
                tmp[0] = max(arr[i][0],brr[j][0]);
                tmp[1] = min(arr[i][1],brr[j][1]);
                result.push_back(tmp);
                //now which one to increment....
                if(arr[i][1]<brr[j][1]){
                    ++i;
                }else if(brr[j][1]<arr[i][1]){
                    ++j;
                }else if(arr[i][1]==brr[j][1]){
                    ++i;
                    ++j;
                }
            }
        }
        return result;
    }
};
