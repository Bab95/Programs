class Solution {
    public int max(int a,int b){
        if(a>b){
            return a;
        }
        return b;
    }
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==0){
            return 0;
        }
        int ans = -1;
        int mmap[] = new int[256];
        for(int i=0;i<256;++i){
            mmap[i] = -1;
        }
        int currentLength = 0;
        for(int i=0;i<s.length();++i){
            char current = s.charAt(i);
            if(mmap[current]==-1||i-currentLength>mmap[current]){
               currentLength++;
            }else{
                ans = max(ans,currentLength);
                currentLength = i-mmap[current];
            }
            mmap[current] = i;
        }
        ans = max(currentLength,ans);
        return ans;
    }
}
