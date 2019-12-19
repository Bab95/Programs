#include <vector>
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len<=2){
            return s;
        }
        if(numRows==1){
            return s;
        }
        vector<char> v[numRows];
        bool down = true;
        int j = 1;
        v[0].push_back(s[0]);
        for(int i=1;i<len;i++){
            if(down){
                if(j!=numRows){
                    v[j].push_back(s[i]);
                    j++;
                }else{
                    j = j-2;
                    down = !down;
                    v[j].push_back(s[i]);
                    j--;
                }
            }else{
                if(j!=-1){
                    v[j].push_back(s[i]);
                    j--;
                }else{
                    j = j+2;
                    down = !down;
                    v[j].push_back(s[i]);
                    j++;
                }
            }
        }
        string result;
        vector<char>::iterator itr;
        for(int i=0;i<numRows;i++){
            for(itr=v[i].begin();itr!=v[i].end();itr++){
                result.push_back(*itr);
            }
        }
      return result;
    }
};
