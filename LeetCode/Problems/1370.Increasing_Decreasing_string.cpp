class Solution {
public:
    string sortString(string s) {
        string result;
        unordered_map<char, int> mmap;
        for (auto c : s){
            mmap[c] += 1;
        }
        int len = 0;
        bool increasing = true;
        int c = 0;
        while (len < s.length()){
            char current = c + 'a';
            if (mmap.find(current) != mmap.end()){
                result.push_back(current);
                mmap[current] -= 1;
                if (mmap[current] == 0){
                    mmap.erase(current);
                }
                len++;
            }
            if (increasing){
                if (c == 25){
                    increasing = false;
                }else{
                    c++;
                }
            }else{
                if (c == 0){
                    increasing = true;
                }else{
                    c--;
                }
            }
        }
        return result;
    }
};