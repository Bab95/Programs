class Solution {
public:
    void generate(vector<string>& ans,int left,int right,int n,string current){
        if(right>left){
            return;
        }
        if(left==n){
            if(right==n){
                ans.push_back(current);
                return;
            }else{
                generate(ans,left,right+1,n,current+")");
            }
        }else{
            generate(ans,left+1,right,n,current+"(");
            generate(ans,left,right+1,n,current+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        generate(ans,0,0,n,current);
        return ans;
    }
};
