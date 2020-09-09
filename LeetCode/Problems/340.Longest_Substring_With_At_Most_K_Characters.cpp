/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.

*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.length()==0||k==0){
            return 0;
        }
        unordered_map<char,int> mmap;
        int start = 0;
        int len = -1;
        for(int i=0;i<s.length();++i){
            if(mmap.find(s[i])==mmap.end()){
                mmap[s[i]] = 1;
            }else{
                mmap[s[i]] += 1;
            }
            if(mmap.size()<=k){
                len = max(len,i-start+1);
            }else{
                while(mmap.size()>k){
                    mmap[s[start]]-=1;
                    if(mmap[s[start]]==0){
                        mmap.erase(s[start]);
                    }
                    start++;
                }
                if(mmap.size()<=k){
                    len = max(len,i-start+1);
                }
            }
        }
        return len;
    }
};
