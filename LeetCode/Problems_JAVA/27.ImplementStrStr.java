class Solution {
    public int strStr(String text, String pattern) {
        //building longestPrefixSuffixArray......
        int p = pattern.length();
        if(p==0){
            return 0;
        }
        int[] longestSuffixPrefix = new int[p];
        int i = 0;
        int j = i+1;
        while(j<p){
            if(pattern.charAt(i)==pattern.charAt(j)){
                longestSuffixPrefix[j] = i+1;
                j++;
                i++;
            }else{
                if(i==0){
                    longestSuffixPrefix[j] = 0;
                    j++;
                }else{
                    i = longestSuffixPrefix[i-1];
                }
            }
        }
        int index = 0;
        j = 0;
        while(index<text.length()){
            if(text.charAt(index)==pattern.charAt(j)){
                index++;
                j++;
            }
            if(j==p){ //found a match......
                return index-p;
            }else{
                //now two cases either we are at begining or in between the pattern.....
                if(index<text.length()&&text.charAt(index)!=pattern.charAt(j)){
                    if(j>0){
                        //move to lps index......
                        j = longestSuffixPrefix[j-1];
                    }else{
                        //if at the begining then just move in the text.....
                        index++;
                    }
                }
            }
        }
        return -1;
    }
}
