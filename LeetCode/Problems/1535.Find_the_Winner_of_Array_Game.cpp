class Solution {
public:
    struct comp
    {
	    template<typename T>
	    bool operator()(const T& l, const T& r) const
	    {
		    return l.first>r.first;
	    }
    };

    int max_element(vector<int>& arr){
        int ans = arr[0];
        for(int i=1;i<arr.size();++i){
            ans = max(arr[i],ans);
        }
        return ans;
    }
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()-1){
            return max_element(arr);
        }
        set<pair<int,int>, comp > tree;
        for(int i=0;i<=min((int)arr.size()-1,k);++i){
            tree.insert({arr[i],i});
        }
        for(int i=k;i<arr.size();++i){
            auto it = tree.begin();
            if(i-it->second==k){
                return it->first;
            }
            pair<int,int> p;
            p.first = arr[i-k];
            p.second = i-k;
            tree.erase(p);
            tree.insert(make_pair(arr[i],i));

        }
        return max_element(arr);
    }
};
