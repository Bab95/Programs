class Solution {
public:
    string common_prefix(string& a,string& b){
        int i = 0;
        while(i<a.length()&&i<b.length()){
            if(a[i]!=b[i]){
                break;
            }
            i++;
        }
        if(i==0){
            return "";
        }
        return a.substr(0,i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }
        string s = common_prefix(strs[0],strs[1]);
        for(int i=2;i<strs.size();++i){
            s = common_prefix(strs[i],s);
        }
        return s;
    }
};
