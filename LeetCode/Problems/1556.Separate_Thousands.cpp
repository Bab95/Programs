class Solution {
public:
    string thousandSeparator(int n) {
        string ans;
        ans = to_string(n);
        string res;
        int k = 0;
        for(int i=ans.length()-1;i>=0;i--){
            res.push_back(ans[i]);
            k++;
            if(k%3==0){
                res.push_back('.');
            }
        }
        if(res[res.length()-1]=='.'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        return res;
    }

};
