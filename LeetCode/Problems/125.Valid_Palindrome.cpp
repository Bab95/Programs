class Solution {
public:
    char tolower(char s){
        if(s>='A'&&s<='Z'){
            s = s-'A'+'a';
        }
        return s;
    }
    string convert_to_usable(string& s){
        stringstream ss(s);
        string word;
        string ans;
        while(ss>>word){
            for(int i=0;i<word.size();++i){
                if((word[i]>='a'&&word[i]<='z')||(word[i]>='A'&&word[i]<='Z')||(word[i]>='0'&&word[i]<='9')){
                    ans.push_back(tolower(word[i]));
                }
            }
        }
        return ans;
    }
    bool ispalindrome(string& s){
        if(s.length()==0){
            return true;
        }
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
    bool isPalindrome(string s) {
        s = convert_to_usable(s);
        //cout<<s<<endl<<s.length()<<endl;
        if(ispalindrome(s)){
            return true;
        }
        return false;
    }
};
