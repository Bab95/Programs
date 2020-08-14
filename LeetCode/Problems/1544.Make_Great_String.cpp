class Solution {
public:
    string makeGood(string s) {
        int diff = abs('a'-'A');
        int len = s.length();
        while(len>0){
            bool flag = false;
            for(int i=0;i<s.length()-1;){
                char _c = s[i+1];
                if(abs(s[i]-s[i+1]) == diff){
                    s[i] = '#';
                    s[i+1] = '#';
                    flag = true;
                    i += 2;
                }else{
                    ++i;
                }
            }
            if(!flag){
                return s;
            }
            int index = 0;
            for(int i=0;i<s.length();++i){
                if(s[i]!='#'){
                    s[index++] = s[i];
                }
            }
            s = s.substr(0,index);
            len = s.length();
            //cout<<s<<endl;
        }
        return s;
    }
};
