class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_occurence(26, -1);
        for (int i=0;i<s.length();i++){
            last_occurence[s[i]-'a'] = i;
        }
        stack<char> stk;
        vector<bool> in_stack(26, false);
        for (int i=0;i<s.length();i++){
            if (!in_stack[s[i]-'a']){
                while (!stk.empty() && stk.top() > s[i] && last_occurence[stk.top()-'a'] > i){
                    in_stack[stk.top()-'a'] = false;
                    stk.pop();

                }
                in_stack[s[i]-'a'] = true;
                stk.push(s[i]);
            }
        }
        string result = "";
        while (!stk.empty()){
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};
