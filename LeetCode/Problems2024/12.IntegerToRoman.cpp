class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mmap;
        mmap[1] = "I";
        mmap[4] = "IV";
        mmap[5] = "V";
        mmap[9] = "IX";
        mmap[10] = "X";
        mmap[40] = "XL";
        mmap[50] = "L";
        mmap[90] = "XC";
        mmap[100] = "C";
        mmap[400] = "CD";
        mmap[500] = "D";
        mmap[900] = "CM";
        mmap[1000] = "M";
        string result;
        vector<int> sym = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int i = sym.size() - 1;
        while (num && i >= 0) {
            while (num - sym[i] >= 0) {
                result += mmap[sym[i]];
                num = num-sym[i];
            }
            i--;
        } 
        return result;
    }
};
