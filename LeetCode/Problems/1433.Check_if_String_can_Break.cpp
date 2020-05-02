class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        bool s1break2 = true;
        bool s2break1 = true;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        //s1 break s2;
        int i = 0;
        while(i<s1.length()){
            if(s1[i]>=s2[i]){
                i++;
            }else{
                s1break2 = false;
                break;
            }
        }
        i = 0;
        while(i<s2.length()){
            if(s2[i]>=s1[i]){
                i++;
            }else{
                s2break1 = false;
                break;
            }
        }

        return (s1break2 || s2break1);
    }
};
