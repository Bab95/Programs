class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string> > symbols;
        symbols.push_back(make_pair<int,string>(1,"I"));
        symbols.push_back(make_pair<int,string>(2,"II"));
        symbols.push_back(make_pair<int,string>(3,"III"));
        symbols.push_back(make_pair<int,string>(4,"IV"));
        symbols.push_back(make_pair<int,string>(5,"V"));
        symbols.push_back(make_pair<int,string>(9,"IX"));
        symbols.push_back(make_pair<int,string>(10,"X"));
        symbols.push_back(make_pair<int,string>(40,"XL"));
        symbols.push_back(make_pair<int,string>(50,"L"));
        symbols.push_back(make_pair<int,string>(90,"XC"));
        symbols.push_back(make_pair<int,string>(100,"C"));
        symbols.push_back(make_pair<int,string>(400,"CD"));
        symbols.push_back(make_pair<int,string>(500,"D"));
        symbols.push_back(make_pair<int,string>(900,"CM"));
        symbols.push_back(make_pair<int,string>(1000,"M"));
        string result;
        int j = symbols.size()-1;
        while(num>0){
            int i = num/symbols[j].first;
            while(i>0){
                result.append(symbols[j].second);
                --i;
            }
            num = num%symbols[j].first;
            j--;
        }
        return result;
    }
};
