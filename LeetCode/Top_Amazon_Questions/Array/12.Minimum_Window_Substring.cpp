class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hasht(256,0);
        for(int i=0;i<t.length();++i){
            hasht[t[i]] += 1;
        }
        vector<int> hashs(256,0);
        int start = -1;
        int found_length = 0;
        int len = t.length();
        int current_start = 0;
        int min_length = INT_MAX;
        for(int i=0;i<s.length();++i){
            if(hashs[s[i]]<hasht[s[i]]){
                found_length++;
                hashs[s[i]]++;
            }else{
                hashs[s[i]]++;
            }
            if(found_length==len){
                while(hashs[s[current_start]]>hasht[s[current_start]]||hasht[s[current_start]]==0){

                    hashs[s[current_start]]--;
                    current_start++;
                }
                int current_length = i-current_start+1;
                if(current_length<=min_length){
                    min_length = current_length;
                    start = current_start;
                }
            }
        }
        string ans = "";
        if(start!=-1){
            ans = s.substr(start,min_length);
            return ans;
        }
        return ans;
    }
};
