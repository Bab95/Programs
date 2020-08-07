class Solution {
public:
    bool contain_digit(string& s){
        for(auto &c : s){
            if(c>='0'&&c<='9'){
                return true;
            }
        }
        return false;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        if(logs.size()==0){
            return logs;
        }
        vector<string> digit_logs,alpha_logs;
        for(auto &s: logs){
            int _space = s.find(' ');
            string tmp = s.substr(_space,s.length()-_space);
            if(contain_digit(tmp)){
                digit_logs.push_back(s);
            }else{
                alpha_logs.push_back(s);
            }
        }
        sort(alpha_logs.begin(),alpha_logs.end(),[](const string& s1,const string& s2){
            int _space = s1.find(' ');
            string a = s1.substr(_space,s1.length()-_space);
            string tag_a = s1.substr(0,_space);
            _space = s2.find(' ');
            string b = s2.substr(_space,s2.length()-_space);
            string tag_b = s2.substr(0,_space);
            if(a==b){
                return tag_a<tag_b;
            }
            return a<b;
        });
        int k = 0;
        for(auto &it : alpha_logs){
            logs[k++] = it;
        }
        for(auto &it : digit_logs){
            logs[k++] = it;
        }
        return logs;
    }
};
