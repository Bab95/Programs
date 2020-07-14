class Solution {
public:
    bool is_valid(string s){
        if(s[0]=='2'){
            if(s[1]<='3'){
                if(s[2]<='5'){
                    return true;
                }
            }else{
                return false;
            }
        }else if(s[0]=='1'||s[0]=='0'){
            //no need to check s[1]...
            if(s[2]<='5'){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end());
        string current;
        for(int i=0;i<A.size();++i){
            current.push_back(A[i]+'0');
        }
        string ans = "";
        if(is_valid(current)){
            ans = current;
        }
        //cout<<current<<endl;
        do{
            //cout<<current<<endl;
            if(is_valid(current)&&current>ans){
                ans = current;
            }
        }while(next_permutation(current.begin(),current.end()));
        string result;
        if(ans==""){
            return ans;
        }
        result.append(ans.substr(0,2));
        result.push_back(':');
        result.append(ans.substr(2,2));
        return result;
    }
};
