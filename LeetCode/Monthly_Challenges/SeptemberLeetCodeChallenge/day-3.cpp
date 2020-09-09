class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=1;i<=s.length()/2;++i){
            if(s.length()%i!=0){
                continue;
            }
            bool flag = true;
            for(int j=0;j<i;++j){
                for(int k=i+j;k<s.length();k+=i){
                    if(s[j]!=s[k]){
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
            if(flag==true){
                return true;
            }
        }
        return  false;
    }
};
