class Solution {
public:
    int minInsertions(string s) {
        stack<char> stk;
        int ans = 0;
        for(int i=0;i<s.length();){
            if(s[i]==')'){
                char current = s[i];
                int count = 0;
                while(i<s.length() && s[i]==current){
                    i++;
                    count++;
                }
                if(count%2==1){
                    count += 1;
                    ans += 1;
                }
                while(!stk.empty()&&count>0){
                    stk.pop();
                    count -= 2;
                }
                if(stk.empty()&&count!=0){
                    ans += count/2;
                }
            }else{
                stk.push(s[i]);
                i++;
            }
        }
        while(!stk.empty()){
            ans += 2;
            stk.pop();
        }
        return ans;
    }
};
