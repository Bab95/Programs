class Solution {
public:
    string reverseOnlyLetters(string s) {
        if(s.length()==0){
            return s;
        }
        vector<int> indexes;
        for(int i=0;i<s.length();++i){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                indexes.push_back(i);
            }
        }
        int l = 0;
        int r = indexes.size()-1;
        while(l<r){
            swap(s[indexes[l]],s[indexes[r]]);
            ++l;
            --r;
        }
        return s;
    }
};
