class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        int i=0,j=0,k=0;
        while(i<arr1.size()&&j<arr2.size()&&k<arr3.size()){
            if(arr1[i]==arr2[j]&&arr2[j]==arr3[k]){
                ans.push_back(arr1[i]);
                ++i;
                ++j;
                ++k;
            }else{
                int _m = min(arr1[i],min(arr2[j],arr3[k]));
                if(_m==arr1[i]){
                    ++i;
                }
                if(_m==arr2[j]){
                    ++j;
                }
                if(_m==arr3[k]){
                    ++k;
                }
            }
        }
        return ans;
    }
};
