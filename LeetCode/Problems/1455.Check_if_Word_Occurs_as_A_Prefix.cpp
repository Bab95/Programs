class Solution {
public:
    bool isPrefix(string& word,string& s){
        if(s[0]!=word[0]){
            return false;
        }
        if(s.length()>word.length()){
            return false;
        }
        int i = 0;
        while(i<s.length()){
            if(s[i]!=word[i]){
                return false;
            }
            i++;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int ans = 1;
        while(ss>>word){
            if(isPrefix(word,searchWord)){
                return ans;
            }
            ans++;
        }
        return -1;
    }
};
