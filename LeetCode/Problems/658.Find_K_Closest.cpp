class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multiset<pair<int,int> > ss;
        for(int i=0;i<arr.size();++i){
            ss.insert(make_pair(abs(arr[i]-x),arr[i]));
        }
        vector<int> ans;
        ans.reserve(k);
        for(auto it=ss.begin();it!=ss.end();++it){
            ans.push_back(it->second);
            if(ans.size()==k){
                break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
