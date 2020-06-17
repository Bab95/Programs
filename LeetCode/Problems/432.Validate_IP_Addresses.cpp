class Solution {
public:
    bool valid_int(string s){
        if(s.length()==0){
            return false;
        }
        if(s[0]=='0'&&s.length()>1){
            return false;
        }
        if(s.length()>3){
            return false;
        }
        for(auto c : s){
            if(c>='0'&&c<='9'){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    bool valid_hex(string& s){
        if(s.length()==0){
            return false;
        }
        if(s.length()>4){
            return false;
        }
        for(auto c: s){
            if((c>='0'&&c<='9')||(c>='a'&&c<='f')||(c>='A'&&c<='F')){
                continue;
            }else{
                return false;
            }
        }
        for(int i=0;i<s.length();++i){
            if(s[i]>='A'&&s[i]<='F'){
                s[i] = s[i]-'A'+'a';
            }
        }
        return true;
    }
    vector<string> split(string IP){
        vector<string> ans;
        string current;
        for(int i=0;i<IP.length();++i){
            if(IP[i]=='.'||IP[i]==':'){
                ans.push_back(current);
                current.clear();
            }else{
                current.push_back(IP[i]);
            }
        }
        ans.push_back(current);
        return ans;
    }
    string validIPAddress(string IP) {
        vector<string> parts = split(IP);
        if(parts.size()==4){
            //ipv4....
            for(auto it : parts){
                if(!valid_int(it)){
                    return "Neither";
                }
                int a = stoi(it);
                if(a>255||a<0){
                    return "Neither";
                }
            }
            return "IPv4";
        }else if(parts.size()==8){
            //string hex_str = "0x";
            for(auto it : parts){
                if(!valid_hex(it)){
                    cout<<"that"<<endl;
                    return "Neither";
                }
                //hex_str = hex_str.append(it);
                stringstream ss;
                unsigned int x;
                ss<<std::hex<<it;
                ss>>x;
                if(x>65535||x<0){
                    cout<<x<<endl;
                    cout<<"this.."<<endl;
                    return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};
