class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash_str(256,0);
        vector<int> hash_p(256,0);
        for(int i=0;i<t.length();i++){
            hash_p[t[i]]++;
        }
        int count = 0;
        int len = t.length();
        int start = 0;
        int min_length = INT_MAX;
        int start_index = -1;
        for(int i=0;i<s.length();i++){
            hash_str[s[i]]++;
            if(hash_p[s[i]]!=0&&hash_str[s[i]]<=hash_p[s[i]]){
                count++;
            }
            if(count==len){
                while(hash_str[s[start]]>hash_p[s[start]]||hash_str[s[start]]==0){
                    if(hash_str[s[start]]>hash_p[s[start]]){
                        hash_str[s[start]]--;
                    }
                    start++;
                }

                int window_length = i-start+1;
                if(min_length>window_length){
                    min_length = window_length;
                    start_index = start;
                    //cout<<start<<" "<<min_length<<endl;
                }
            }

        }
        string result;
        if(start_index!=-1){
            result = s.substr(start_index,min_length);
        }
        return result;
    }
};
