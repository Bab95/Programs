class Solution {
public:
    void generate(string& digits,int index,vector<string>& result,vector<string>& digitsToAlpha,string& current){
        if(current.length()==digits.length()){
            result.push_back(current);
            //cout<<current<<endl;
            return;
        }
        for(int i=0;i<digitsToAlpha[digits[index]-'0'].length();++i){
            current.push_back(digitsToAlpha[digits[index]-'0'][i]);
            generate(digits,index+1,result,digitsToAlpha,current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0){
            return result;
        }
        vector<string> digitsToAlpha =  {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index = 0;
        string current;
        generate(digits,index,result,digitsToAlpha,current);
        return result;
    }
};
