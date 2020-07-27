class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int k = 0;
        while(i<chars.size()){
            char current = chars[i];
            int count = 0;
            while(i<chars.size()&&chars[i]==current){
                i++;
                count++;
            }
            if(count==1){
                chars[k++] = current;
                continue;
            }
            chars[k++] = current;
            string s = to_string(count);
            for(int j=0;j<s.length();++j){
                chars[k++] = s[j];
            }
        }
        return k;
    }
};
