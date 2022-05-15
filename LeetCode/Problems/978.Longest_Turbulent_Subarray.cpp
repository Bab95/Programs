class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int i = 1;
        int maxlength = 1;
        while (i<arr.size()){
            int j = i-1;
            int k = i;
            int start = j;
            if (arr[i] < arr[j]){
                swap(i, j);
            }
            while (k < arr.size() && arr[j] < arr[i]){
                maxlength = max(maxlength, k-start);
                k++;
                j++;
                i++;
                swap(i, j);
            }
            if (k-start > 1){
                maxlength = max(maxlength, k-start);
                i = k;
            }else{
                i++;
            }
        }
        return maxlength;
    }
};
