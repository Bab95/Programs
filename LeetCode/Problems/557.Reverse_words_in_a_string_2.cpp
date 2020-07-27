class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==0){
            return s;
        }
        int j = 0;
        for(int i=0;i<s.length();++i){
            if(s[i]==' '){
                int k = i-1;
                while(j<k){
                    swap(s[j],s[k]);
                    j++;
                    k--;
                }
                j = i+1;
            }
        }
        int k = s.length()-1;
        while(j<k){
            swap(s[j],s[k]);
            j++;
            k--;
        }
        return s;
    }
};
