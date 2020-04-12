class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int n = S.size();
        int i = 0;
        //removing front backspaces......
        while(i<n&&S[i]=='#'){
            ++i;
        }
        int current = 0;
        for(;i<n;++i){
            if(S[i]=='#'){
                current = max(0,current-1);
            }else{
                S[current] = S[i];
                ++current;
            }
        }
        int s_length = current;
        i = 0;
        current = 0;
        n = T.length();
        while(i<n&&T[i]=='#'){
            ++i;
        }
        for(;i<n;++i){
            if(T[i]=='#'){
                current = max(0,current-1);
            }else{
                T[current] = T[i];
                ++current;
            }
        }
        int t_length = current;
        if(s_length!=t_length){
            return false;
        }
        i=0;
        //cout<<s_length<<" "<<t_length<<endl;
        while(i<s_length){
            if(S[i]!=T[i]){
                return false;
            }
            ++i;
        }
        return true;
    }
};
