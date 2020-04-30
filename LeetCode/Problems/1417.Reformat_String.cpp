class Solution {
public:
    string reformat(string s) {
        if(s.length()==1){
            return s;
        }
        int nums = 0;
        int chars = 0;
        sort(s.begin(),s.end());
        if((s[0]>=97||s[s.length()-1]<59)&&s.length()>1){
            return "";
        }
        while(nums<s.length()&&s[nums]<97){
            nums++;
        }
        chars = s.length()-nums;
        if(abs(nums-chars)>1){
            return "";
        }
        string ans;
        ans.reserve(s.length());
        int l = 0;
        int r = s.length()-1;
        if(nums>chars){
            //1 more num
            ans.push_back(s[l++]);
            while(l<r){
                ans.push_back(s[r--]);
                ans.push_back(s[l++]);
            }
        }else if(nums==chars){
            while(l<r){
                ans.push_back(s[l++]);
                ans.push_back(s[r--]);
            }
        }else{
            //1 more char...
            ans.push_back(s[r--]);
            while(l<r){
                ans.push_back(s[l++]);
                ans.push_back(s[r--]);
            }
        }
        return ans;
    }
};
