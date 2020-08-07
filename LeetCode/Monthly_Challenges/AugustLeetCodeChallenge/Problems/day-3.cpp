class Solution {
public:
    void preprocess_string(string& s){
        int k = 0;
        for(int i=0;i<s.length();++i){
            if(s[i]>='A'&&s[i]<='Z'){
                s[k] = s[i] - 'A' + 'a';
                k++;
            }else if(s[i]>='a'&&s[i]<='z'){
                s[k] = s[i];
                k++;
            }else if(s[i]>='0'&&s[i]<='9'){
                s[k] = s[i];
                k++;
            }
        }
        s = s.substr(0,k);
    }
    bool isPalindrome(string s) {
        if(s.length()<=1){
            return true;
        }
        preprocess_string(s);
        cout<<s<<endl;
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
