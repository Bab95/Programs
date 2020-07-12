class Solution {
public:
    vector<string> split(string& s){
        vector<string> ans;
        string current;
        for(int i=0;i<s.length();++i){
            if(s[i]==' '){
                ans.push_back(current);
                current.clear();
            }else{
                current.push_back(s[i]);
            }
        }
        ans.push_back(current);
        return ans;
    }
    string reformatDate(string date) {
        unordered_map<string,int> mmap;
        vector<string> _year = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        for(int i=1;i<=_year.size();++i){
            mmap[_year[i-1]] = i;
        }
        vector<string> _date = split(date);
        int _dd = stoi(_date[0]);
        int _yy = stoi(_date[2]);
        int _mm = mmap[_date[1]];

        string ans;
        ans = ans.append(to_string(_yy));
        ans.push_back('-');
        if(_mm<10){
            ans.push_back('0');
        }
        ans = ans.append(to_string(_mm));
        ans.push_back('-');
        if(_dd<10){
            ans.push_back('0');
        }
        ans = ans.append(to_string(_dd));
        return ans;
    }
};
