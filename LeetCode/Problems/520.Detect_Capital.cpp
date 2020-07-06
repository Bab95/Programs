class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()==1){
            return true;
        }
        bool start_capital = false;
        bool between = false;
        if(word[0]>='A'&&word[0]<='Z'){
            start_capital = true;
        }
        if(!start_capital){
            for(int i=1;i<word.length();++i){
                if(word[i]>='A'&&word[i]<='Z'){
                    return false;
                }
            }
            return true;
        }else{
            //two cases either all capital or rest small....
            bool f1 = true;
            bool f2 = true;

            for(int i=1;i<word.length();++i){
                if(word[i]>='A'&&word[i]<='Z'){
                    f1 = false;
                }
            }

            for(int i=1;i<word.length();++i){
                if(word[i]>='a'&&word[i]<='z'){
                    f2 = false;
                }
            }
            return f1||f2;
        }
        return false;
    }
};
