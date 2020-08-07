class Solution {
public:
    int nCk(int n,int k){
        int combination = 1;
        for(int i=1;i<=k;++i){
            combination *= (n-(k-i));
            combination /= i;
        }
        return combination;
    }
    void find_combination(vector<int>& arr,vector<vector<int> >& ans,vector<int>& combination,int k,int index,int& combination_index){
        if(combination.size()==k){
            ans[combination_index++] = combination;
            return;
        }
        for(int i=index;i<arr.size();++i){
            combination.push_back(arr[i]);
            find_combination(arr,ans,combination,k,i+1,combination_index);
            combination.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(k>n){
            return {};
        }
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            arr[i] = i+1;
        }
        int total_combinations = nCk(n,k);
        vector<vector<int> > ans(total_combinations);
        vector<int> combination;
        int index = 0;
        int combination_index = 0;
        find_combination(arr,ans,combination,k,index,combination_index);
        return ans;
    }
};
