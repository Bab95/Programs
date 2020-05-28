class Solution {
public:
    bool equal(string& a,string& b){
        int i = 0;
        while(i<a.length()){
            if(a[i]!=b[i]){
                return false;
            }
            i++;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length()){
            return {};
        }
        vector<int> hash_p(26,0);
        vector<int> hash_s(26,0);
        vector<int> ans;
        for(int i=0;i<p.length();++i){
            hash_p[p[i]-'a']++;
        }
        int count = 0;
        int start = 0;
        for(int i=0;i<s.length();++i){
            hash_s[s[i]-'a']++;
            if(hash_s[s[i]-'a']<=hash_p[s[i]-'a']){
                count++;
            }
            if(count==p.length()){
                while(hash_p[s[start]-'a']==0||hash_s[s[start]-'a']>hash_p[s[start]-'a']){
                    hash_s[s[start]-'a']--;
                    start++;
                }
                if(i-start+1==p.length()){
                    ans.push_back(start);
                }

            }
        }
        return ans;
    }
};
