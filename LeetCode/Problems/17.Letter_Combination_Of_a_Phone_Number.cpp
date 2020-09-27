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

/*Solution*/
class Solution {
public:
    void find_combination(string& digit,vector<string>& ans,string current,unordered_map<char,string>& mmap){
        if(current.length()==digit.length()){
            ans.push_back(current);
            return;
        }
        int current_digit = current.length();
        for(int i=0;i<mmap[digit[current_digit]].length();++i){
            current.push_back(mmap[digit[current_digit]][i]);
            find_combination(digit,ans,current,mmap);
            current.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        unordered_map<char,string> mmap;
        mmap['2'] = "abc";
        mmap['3'] = "def";
        mmap['4'] = "ghi";
        mmap['5'] = "jkl";
        mmap['6'] = "mno";
        mmap['7'] = "pqrs";
        mmap['8'] = "tuv";
        mmap['9'] = "wxyz";
        string current = "";
        vector<string> ans;
        find_combination(digits,ans,current,mmap);
        return ans;
    }
};