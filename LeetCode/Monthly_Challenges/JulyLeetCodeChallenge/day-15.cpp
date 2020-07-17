class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==0){
            return "";
        }
        stringstream ss(s);
        string word;
        s.clear();
        while(ss>>word){
            word.push_back(' ');
            s = word.append(s);
            //s.push_back(' ');
        }
        if(s.length()>0){
            s.pop_back();
        }
        return s;
    }
};
