class Solution {
public:
    bool valid_time(string& s){
        if(s.length()!=4){
            return false;
        }
        int a = (s[0]-'0')*10 + (s[1]-'0');
        int b = (s[2]-'0')*10 + (s[3]-'0');
        if(a>=24){
            return false;
        }
        if(b>=60){
            return false;
        }
        return true;
    }
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end());
        string ans;
        for(int i=0;i<A.size();++i){
            ans.push_back(A[i]+'0');
        }
        string current;
        for(int i=0;i<ans.length();++i){
            current.push_back(ans[i]);
        }
        if(!valid_time(ans)){
            ans = "";
        }
        while(next_permutation(current.begin(),current.end())){
            if(valid_time(current)&&current>ans){
                ans = current;
            }
        }
        if(valid_time(ans)){
            string result;
            result.push_back(ans[0]);
            result.push_back(ans[1]);
            result.push_back(':');
            result.push_back(ans[2]);
            result.push_back(ans[3]);
            return result;
        }
        return "";
    }
};
