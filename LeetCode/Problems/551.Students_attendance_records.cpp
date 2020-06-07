class Solution {
public:
    bool checkRecord(string s) {
        int a_count = 0;
        bool absents = true;
        bool late = true;
        for(int i=0;i<s.length();++i){
            if(s[i]=='A'){
                a_count++;
            }else if(s[i]=='L'){
                int count = 0;
                int j = i;
                while(j<s.length()&&s[j]==s[i]){
                    count++;
                    ++j;
                }
                if(count>2){
                    late = false;
                }
            }
        }

        if(a_count>1){
            absents = false;
        }
        return late&&absents;
    }
};
