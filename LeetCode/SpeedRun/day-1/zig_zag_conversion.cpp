class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<string> tmp(numRows);
        int i = 0;
        int index = 0;
        bool down = true;
        while(i<s.length()){
            tmp[index].push_back(s[i]);
            if(down){
                if(index==numRows-1){
                    index--;
                    down = !down;
                }else{
                    index++;
                }
            }else{
                if(index==0){
                    index++;
                    down = !down;
                }else{
                    index--;
                }
            }
            ++i;
        }
        string ans;
        for(auto str : tmp){
            ans = ans.append(str);
        }
        return ans;
    }
};
