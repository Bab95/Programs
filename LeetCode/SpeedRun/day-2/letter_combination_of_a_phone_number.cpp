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
