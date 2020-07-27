class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        vector<bool> present(40501,false);
        vector<int> repeated;
        for(auto i : A){
            if(!present[i]){
                present[i] = true;
            }else{
                repeated.push_back(i);
            }
        }
        long int ans = 0;
        sort(repeated.begin(),repeated.end());
        int previous = 0;
        for(int i=0;i<repeated.size();++i){
            int current = repeated[i];
            if(current<previous){
                current = previous;
            }
            while(present[current]){
                current++;
            }
            present[current] = true;
            previous = current;
            ans += (current-repeated[i]);
        }
        return ans;
    }
};
