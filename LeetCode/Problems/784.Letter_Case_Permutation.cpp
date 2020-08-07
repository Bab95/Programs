class Solution {
public:
    void permute_letter(vector<int>& indexes,string& S,int index,int n,vector<string>& ans,int& permute_index){
        if(permute_index==ans.size()){
            return;
        }
        ans[permute_index++] = S;
        for(int i=index;i<n;++i){
            int _index = indexes[i];
            S[_index] = S[_index]- 'a' + 'A';
            permute_letter(indexes,S,i+1,n,ans,permute_index);
            S[_index] = S[_index] - 'A' + 'a';
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<int> indexes;
        for(int i=0;i<S.length();++i){
            if(S[i]>='A'&&S[i]<='Z'){
                S[i] = S[i]- 'A' + 'a';
                indexes.push_back(i);
            }else if(S[i]>='a'&&S[i]<='z'){
                indexes.push_back(i);
            }
        }
        int n = indexes.size();
        if(n==0){
            return {S};
        }
        int total = pow(2,n);
        vector<string> ans(total);
        int _n = indexes.size();
        int permute_index = 0;
        for(int i=0;i<indexes.size();++i){
            permute_letter(indexes,S,i,_n,ans,permute_index);
        }
        return ans;
    }
};
