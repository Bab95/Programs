#include <map>
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string letters[9] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int startIndex = 0;
        int currentsize = 0;
        if(digits.length()==0){
            return vector<string> {};
        }
        vector<string> res;
        for(const char& c:letters[(int)digits[0]-48-1]){
            res.push_back(string(1,c));
        }
        for(int i=1;i<digits.length();i++){
            currentsize = res.size();
            int index = (int)digits[i]-48-1;
            for(int a=startIndex;a<currentsize;a++){
                for(const char& v:letters[index]){
                    res.push_back(res[a]+v);
                }
            }
            startIndex = currentsize;
        }
        return vector<string>(res.begin()+startIndex,res.end());
    }
};
