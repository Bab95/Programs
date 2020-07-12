class Solution {
public:
    void generate(int open,int close,int n,string current,vector<string>& ans){
        if(close>open){
            return;
        }
        if(open==n){
            if(close==n){
                ans.push_back(current);
            }else{
                current.push_back(')');
                generate(open,close+1,n,current,ans);
            }
            return;
        }else{
            current.push_back('(');
            generate(open+1,close,n,current,ans);
            current.pop_back();
            current.push_back(')');
            generate(open,close+1,n,current,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(0,0,n,"",ans);
        return ans;
    }
};
