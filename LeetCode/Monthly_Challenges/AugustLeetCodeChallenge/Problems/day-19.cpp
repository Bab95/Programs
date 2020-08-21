class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string str;
        string ans="";
        int i = 1;
        while(ss>>str){
            string tmp;
            cout<<str<<" ";
            if(str[0]!='a'&&str[0]!='e'&&str[0]!='i'&&str[0]!='o'&&str[0]!='u'&&str[0]!='A'&&str[0]!='E'&&str[0]!='I'&&str[0]!='O'&&str[0]!='U'){
                for(int j=1;j<str.length();++j){
                    ans.push_back(str[j]);
                }
                ans.push_back(str[0]);
            }else{
                for(int j=0;j<str.length();++j){
                    ans.push_back(str[j]);
                }
            }
            ans.push_back('m');
            ans.push_back('a');
            for(int j=1;j<=i;++j){
                ans.push_back('a');
            }
            ans.push_back(' ');
            i++;
        }
        ans.pop_back();
        return ans;
    }
};
