#include <bits/stdc++.h>
using namespace std;
class Solution{
public:	
    /*Solution
    *Observations:A substrig of length of max len/2 can repeat.
    *So check for all the substrings of length 1 to len/2 if string can be made of current length's repeated substrings
    *[abc]abcabcabc
    *for checking use jumps of current length.....
    */
	int isRepeat(string s)
	{
	    // Your code goes here
	    int slen = s.length();
	    for(int len=1;len<=slen/2;++len){
	        if(slen%len!=0){
	            continue;
	        }
	        bool flag = true;
	        for(int i=0;i<len;i++){
	            for(int j=len+i;j<slen;j+=len){
	                if(s[i]!=s[j]){
	                    flag = false;
	                    break;
	                }
	            }
	        }
	        if(flag==true){
	            return 1;
	        }
	        
	    }
	    return 0;
	}
    int is_Repeated_Using_KMP(string& str){
        int len = str.length();
        vector<int> longestSuffixPrefix(len,0);
        int i = 0;
        int j = i+1;
        int lps_length = 0;
        while(j<len){
            if(str[i]==str[j]){
                longestSuffixPrefix[j] = i+1;
                i++;
                j++;
            }else{
                if(i>0){
                    i = longestSuffixPrefix[i-1];
                }else{
                    longestSuffixPrefix[j] = 0;
                    j++;
                }
            }
        }
        
        //cout<<endl<<lps_length<<endl;
        lps_length = longestSuffixPrefix[len-1];
        if(lps_length==0){
            return 0;
        }
        if(len%(len-lps_length)==0){
            return 1;
        }
        return 0;
    }
};