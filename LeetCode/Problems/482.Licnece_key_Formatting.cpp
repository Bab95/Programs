class Solution {
public:
    string convert(string& s){
        int k = 0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='-'){
                continue;
            }else{
                s[k] = ((s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z'))?s[i]:(s[i]-'a'+'A');
                k++;
            }
        }
        if(k==0){
            return "";
        }
        return s.substr(0,k);
    }
    string licenseKeyFormatting(string S, int K) {
        S = convert(S);
        if(S.length()==0){
            return S;
        }
        string ans;
        int init = S.length()%K;
        if(init!=0){
            ans = S.substr(0,init);
            ans.push_back('-');
        }
        int i = init;
        while(i<S.length()){
            ans = ans.append(S.substr(i,K));
            ans.push_back('-');
            i+=K;
        }
        if(ans[ans.length()-1]=='-'){
            ans.pop_back();
        }
        return ans;
    }
};
