string Solution::minWindow(string A, string B) {
    vector<int> _hash(256,0);
    vector<int> hash(256,0);
    for(int i=0;i<B.length();++i){
        _hash[B[i]] += 1;
    }
    int len = 0;
    int start = 0;
    int minWindow = INT_MAX;
    int start_index = -1;
    for(int i=0;i<A.length();++i){
        hash[A[i]] += 1;
        if(_hash[A[i]]!=0&&_hash[A[i]]>=hash[A[i]]){
            len++;
        }
        
        if(len==B.length()){
            while(hash[A[start]]>_hash[A[start]]||hash[A[start]]==0){
                if(hash[A[start]]>_hash[A[start]]){
                    hash[A[start]]--;
                }
                start++;
            }
            if(i-start+1<minWindow){
                minWindow = i-start+1;
                start_index = start;
            }
        }
    }
    if(minWindow==INT_MAX){
        return "";
    }
    return A.substr(start_index,minWindow);
    
}
