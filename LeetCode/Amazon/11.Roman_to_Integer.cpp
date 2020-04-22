class Solution {
public:
    int romanToInt(string s) {
        map<char,int> symbols;
        symbols.insert(make_pair<char,int>('I',1));
        symbols.insert(make_pair<char,int>('V',5));
        symbols.insert(make_pair<char,int>('X',10));
        symbols.insert(make_pair<char,int>('L',50));
        symbols.insert(make_pair<char,int>('C',100));
        symbols.insert(make_pair<char,int>('D',500));
        symbols.insert(make_pair<char,int>('M',1000));

        int result = symbols[s[s.length()-1]];

        for(int i=s.length()-2;i>=0;i--){
            if(symbols[s[i]]>=symbols[s[i+1]]){
                result+=symbols[s[i]];
            }else{
                result-=symbols[s[i]];
            }
        }
        return result;
    }
};
