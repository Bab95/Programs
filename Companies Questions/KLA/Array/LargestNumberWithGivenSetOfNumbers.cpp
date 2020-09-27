string Solution::largestNumber(const vector<int> &A) {
    vector<string> arr(A.size());
    for(int i=0;i<A.size();++i){
        arr[i] = to_string(A[i]);
    }
    sort(arr.begin(),arr.end(),[](const auto& a,const auto& b){
        string ab = a;
        ab.append(b);
        string ba = b;
        ba.append(a);
        return ab>ba;
    });
    string ans="";
    for(int i=0;i<arr.size();++i){
        ans.append(arr[i]);
    }
    int i = 0;
    while(i<ans.length()&&ans[i]=='0'){
        i++;
    }
    if(i==ans.length()){
        return ans.substr(0,1);
    }
    return ans.substr(i,ans.length()-i+1);
}
