class Solution {
public:
    void getvalid(string& s){
        int k = 0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='+'){
                break;
            }else if(s[i]=='.'){
                continue;
            }else{
                s[k] = s[i];
                ++k;
            }
        }
        s = s.substr(0,k);
    }
    int numUniqueEmails(vector<string>& emails) {
        int unique = 0;
        unordered_map<string,int> mmap;
        for(auto str : emails){
            string local_name = str.substr(0,str.find('@'));
            string host_name = str.substr(str.find('@')+1,str.length()-str.find('@'));
            getvalid(local_name);
            string email = local_name;
            email.push_back('@');
            email = email.append(host_name);
            mmap[email] = 1;
        }
        for(auto it : mmap){
            unique++;
        }
        return unique;
    }
};
