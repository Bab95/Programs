class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==0){
            return "";
        }
        //removing leading spaces....
        int i = 0;
        while(i<s.length()&&s[i]==' '){
            ++i;
        }
        if(i==s.length()){
            return "";
        }
        stringstream ss(s);
        string word;
        s.erase();
        vector<string> strs;
        while(ss>>word){
            strs.push_back(word);
        }
        for(int i=strs.size()-1;i>=0;--i){
            s.append(strs[i]);
            s.push_back(' ');
        }
        s.pop_back();

        return s;
    }
};
