class Solution {
public:
    static bool compare(pair<int,string>& p,pair<int,string>& q){
        if(p.first>q.first){
            return true;
        }
        if(p.first==q.first){
            if(p.second<q.second){
                return true;
            }
        }
        return false;
    }

    string to_lower_string(string& str){
        int k = 0;
        for(int i=0;i<str.length();++i){
            if(str[i]>='A'&&str[i]<='Z'){
                str[k++] = str[i]-'A'+'a';
            }else if(str[i]=='.'||str[i]=='!'||str[i]=='?'||str[i]==','||str[i]==';'||str[i]=='\''){
                continue;
            }else{
                str[k++] = str[i];
            }
        }
        return str.substr(0,k);
    }
    vector<string> break_at_punctuation(string word){
        vector<string> ans;
        string current;
        for(int i=0;i<word.length();++i){
            if(word[i]==','||word[i]=='.'||word[i]=='!'||word[i]=='\''||word[i]=='?'){
                ans.push_back(current);
                current.clear();
            }else{
                current.push_back(word[i]);
            }
        }
        if(current.length()>0){
            ans.push_back(current);
        }
        return ans;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        stringstream ss(paragraph);
        string word;
        unordered_map<string,int> mmap;
        while(ss>>word){
            vector<string> words = break_at_punctuation(word);
            for(auto w : words)
                mmap[to_lower_string(w)]+=1;
        }

        for(auto w : banned){
            mmap[w] = 0;
        }
        pair<int,string> ans;
        ans.first = 0;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if(it->second>ans.first){
                ans.first = it->second;
                ans.second = it->first;
            }else if(it->second==ans.first){
                if(ans.second>it->first){
                    ans.second = it->first;
                }
            }
        }
        return ans.second;
    }
};
