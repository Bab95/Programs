class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.length()<name.length()){
            return false;
        }

        int i = 0;
        int j = 0;
        while(i<name.length()){
            pair<char,int> current;
            current.first = name[i];
            current.second = 0;
            while(i<name.length()&&name[i]==current.first){
                current.second++;
                ++i;
            }
            pair<char,int> typing;
            typing.first = typed[j];
            typing.second = 0;
            if(typing.first!=current.first){
                return false;
            }
            while(j<typed.length()&&typed[j]==typing.first){
                typing.second++;
                ++j;
            }
            if(current.first!=typing.first||typing.second<current.second){
                return false;
            }
        }
        if(j!=typed.length()){
            char last = name[name.length()-1];
            while(j<typed.length()&&last==typed[j]){
                ++j;
            }
            if(j<typed.length()&&typed[j]!=last){
                return false;
            }
        }
        return true;
    }
};
