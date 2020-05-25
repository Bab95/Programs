class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        unordered_map<char,int> mmap;
        mmap['a'] = 0;
        mmap['e'] = 1;
        mmap['i'] = 2;
        mmap['o'] = 3;
        mmap['u'] = 4;
        //vector<char> vovels = {'a','e','i','o','u'};
        //int count = 0;
        int i = 0;
        for(i=0;i<min(k,s.length());i++){
            if(mmap.find(s[i])!=mmap.end()){
                count++;
            }
        }
        int current = count;
        if(i==s.length()){
            return count;
        }
        for(i=k;i<s.length();++i){
            if(mmap.find(s[i-k])!=mmap.end()){
                current--;
            }
            if(mmap.find(s[i])!=mmap.end()){
                current++;
            }
            count = max(current,count);
        }
        return count;
    }
};
