class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int> > stk;
        for(int i=0;i<s.length();){
            char current = s[i];
            int count = 0;
            while(i<s.length()&&current==s[i]){
                count++;
                ++i;
            }
            pair<char,int> _current = {current,count};
            if(stk.empty()){
                stk.push(_current);
            }else{
                pair<char,int> _p = stk.top();
                if(_p.first!=_current.first){
                    _current.second = _current.second%k;
                    if(_current.second>0){
                        stk.push(_current);
                    }
                }else{
                    stk.pop();
                    _current.second = _current.second + _p.second;
                    _current.second = _current.second%k;
                    if(_current.second!=0){
                        stk.push(_current);
                    }
                }
            }
        }
        string ans;
        while(!stk.empty()){
            auto it = stk.top();
            stk.pop();
            for(int i=0;i<it.second;++i){
                ans.push_back(it.first);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
