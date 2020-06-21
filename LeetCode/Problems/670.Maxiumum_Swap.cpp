class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int i = 0;
        while(i<s.length()&&s[i]=='9'){
            ++i;
        }
        for(;i<s.length()-1;++i){
            char current = s[i];
            int ind = -1;
            for(int j=i+1;j<s.length();++j){
                if(s[j]>=current){
                    current = s[j];
                    ind = j;
                }
            }
            if(ind!=-1){
                if(s[i]==s[ind]){
                    continue;
                }
                swap(s[i],s[ind]);
                return stoi(s);
            }
        }
        return num;
    }
};
