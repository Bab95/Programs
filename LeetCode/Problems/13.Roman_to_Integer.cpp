#include <map>
class Solution {
public:
    int romanToInt(string s) {
        if(s.length()==0){
            return 0;
        }
        map<char,int> m;
        m.insert(pair<char,int>('I',1));
        m.insert(pair<char,int>('V',5));
        m.insert(pair<char,int>('X',10));
        m.insert(pair<char,int>('L',50));
        m.insert(pair<char,int>('C',100));
        m.insert(pair<char,int>('D',500));
        m.insert(pair<char,int>('M',1000));
        int len = s.length();
        int result = m[s[len-1]];
        for(int i=len-2;i>=0;i--){
            if(m[s[i]]>=m[s[i+1]]){
                result+=m[s[i]];
            }else{
                result-=m[s[i]];
            }
        }
        return result;
    }
};
