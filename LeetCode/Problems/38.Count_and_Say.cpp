#include <string>
class Solution {
public:
    string countAndSay(int n) {
        string result="";
        if(n==1){
            result = "1";
            return result;
        }
        string prev = "1";
        int k = 2;
        while(k<=n){
            string s;
            //char current = prev[0];
            for(int i=0;i<prev.length();){
                char current = prev[i];
                int count = 1;
                i++;
                while(i<prev.length()&&prev[i]==current){
                    count++;
                    i++;
                }
                string count_string = to_string(count);
                //cout<<"count_string"<<count_string<<endl;
                s.append(count_string);
                s.append(to_string((int)current-48));
            }
            prev = s;
            //cout<<k<<" "<<prev<<endl;
            k++;
        }
        //cout<<prev<<endl;
        return prev;
    }
};
