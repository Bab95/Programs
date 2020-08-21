class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        if(d.size()==0 || s.length()==0){
            return "";
        }
        pair<int,string> ans;
        ans.first = 0;
        ans.second = "";
        int len = s.length();
        for(int i=0;i<d.size();++i){
            if(d[i].length()<ans.first){
                continue;
            }
            if(d[i].length()>len){
                continue;
            }else{
                int p = 0,q=0;
                while(p<len && q<d[i].length()){
                    if(s[p]==d[i][q]){
                        q++;
                    }
                    p++;
                }
                if(q==d[i].length()){
                    if(ans.first==q){
                        ans.second = min(ans.second,d[i]);
                    }else{
                        ans.first = q;
                        ans.second = d[i];
                    }
                }
            }
        }
        return ans.second;
    }
};
