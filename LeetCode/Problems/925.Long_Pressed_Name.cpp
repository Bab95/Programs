class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;
        int j = 0;
        while(i<name.length()&&j<typed.length()){
            int current_count_n = 0;
            char current = name[i];
            int current_typed_count = 0;
            char current_typed = typed[j];
            if(current!=current_typed){
                return false;
            }
            while(i<name.length()&&name[i]==current){
                current_count_n++;
                i++;
            }
            while(j<typed.length()&&typed[j]==current_typed){
                current_typed_count++;
                j++;
            }

            if(current_typed_count<current_count_n){
                return false;
            }
        }
        if(i!=name.length()||j!=typed.length()){
            return false;
        }
        return true;
    }
};
