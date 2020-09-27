class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char,int> mmap;
        for(int i=0;i<secret.length();++i){
            mmap[secret[i]]++;
        }
        for(int i=0;i<secret.length();++i){
            if(secret[i]==guess[i]){
                mmap[guess[i]]-=1;
                bulls++;
                secret[i] = guess[i] = '$';
            }
        }
        for(int i=0;i<secret.length();++i){
            if(secret[i]=='$'){
                continue;
            }else if(secret[i]!=guess[i]){
                if(mmap.find(guess[i])!=mmap.end()&&mmap[guess[i]]!=0){
                    if(mmap[guess[i]]!=0){
                        mmap[guess[i]] -= 1;
                        cows++;
                    }
                }
            }
        }
        string ans = to_string(bulls);
        ans.push_back('A');
        ans = ans.append(to_string(cows));
        ans.push_back('B');
        return ans;
    }
};
