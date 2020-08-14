class Solution {
public:
    string reverseVowels(string s) {
        if(s.length()==0){
            return s;
        }
        vector<int> indexes;
        for(int i=0;i<s.length();++i){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                indexes.push_back(i);
            }else if(s[i]=='A'||s[i]=='E'||s[i]=='O'||s[i]=='I'||s[i]=='U'){
                indexes.push_back(i);
            }
        }
        int l = 0,r = indexes.size()-1;
        /*
        for(auto a : indexes){
            cout<<a<<endl;
        }
        */
        while(l<r){
            swap(s[indexes[l]],s[indexes[r]]);
            l++;
            r--;
        }
        return s;
    }
};
