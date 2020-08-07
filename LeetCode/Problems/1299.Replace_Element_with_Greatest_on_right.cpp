class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        ans[n-1] = -1;
        int current = arr[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i] = current;
            current = max(current,arr[i]);
        }
        return ans;
    }
};
