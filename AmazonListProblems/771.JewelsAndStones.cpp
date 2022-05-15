class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> _jewels;
        int count = 0;
        for (auto j : jewels){
            _jewels.insert(j);
        }
        for (auto s : stones){
            if (_jewels.find(s) != _jewels.end()){
                count++;
            }
        }
        return count;
    }
};