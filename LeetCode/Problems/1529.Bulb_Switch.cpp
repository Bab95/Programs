class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        for(int i=0;i<target.length();++i){
            if(ans%2==0){
                if(target[i]=='1'){
                    ans += 1;
                }
            }else{
                if(target[i]=='0'){
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minFlips(string target) {
        int ans = target[0]-'0';
        for(int i=1;i<target.length();++i){
            if(target[i]!=target[i-1]){
                ans++;
            }
        }
        return ans;
    }
};
