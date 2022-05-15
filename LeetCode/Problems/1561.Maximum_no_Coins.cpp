class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // { 9, 8 , 1} => 8
        // { 7, 6, 2} => 6
        // { 5, 4, 3} => 4 => 18
        sort(piles.begin(), piles.end());
        int ans = 0;
        int _max = piles.size()-1;
        int _min = 0;
        for (int i=0;i<piles.size()/3 && _max > _min;i++){
            int current = piles[_max-1];
            //cout << "debugging::" << current << endl;
            ans += current;
            _max = _max - 2;
            _min++;
        }
        return ans;
    }
};
