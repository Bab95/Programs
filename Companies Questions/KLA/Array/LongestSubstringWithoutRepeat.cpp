int Solution::lengthOfLongestSubstring(string A) {
    vector<int> last(256,-1);
    int current_length = 0;
    int max_length = INT_MIN;
    for(int i=0;i<A.length();++i){
        if(last[A[i]]==-1||i-last[A[i]]>current_length){
            current_length++;
        }else{
            max_length = max(max_length,current_length);
            current_length = i-last[A[i]];
        }
        last[A[i]] = i;
    }
    return max(max_length,current_length);
}
