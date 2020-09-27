class Solution {
public:
    int find_length(string s,int k,int start,int end){
        int left,right;
        vector<int> mmap(26,0);
        for(int i=start;i<end;++i){
            mmap[s[i]-'a']+=1;
        }
        for(int i=start;i<end;++i){
            if(mmap[s[i]-'a']<k){
                left = find_length(s,k,start,i);
                right = find_length(s,k,i+1,end);
                return max(left,right);
            }
        }
        return end-start;
    }
    int longestSubstring(string s, int k) {
        if(k>s.length()||s.length()==0){
            return 0;
        }
        int ans = find_length(s,k,0,s.length());
        return ans;
    }
};
