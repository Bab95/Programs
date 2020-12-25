class Solution {
public:
    void dfs(int i,vector<string>& arr,string& current,int& ans,vector<bool>& hash){
        if(i>=arr.size()){
            return;
        }
        for(int j=i;j<arr.size();++j){
            int k;
            string str = arr[j];
            for(k=0;k<arr[j].length();k++){
                if(!hash[str[k]-'a']){
                    current.push_back(str[k]);
                    hash[str[k]-'a'] = true;
                }else{
                    break;
                }
            }
            if(k<str.length()){
                while(k>0){
                    hash[str[k-1]-'a'] = false;
                    current.pop_back();
                    --k;
                }
            }else{
                ans = max(ans,(int)current.length());
                dfs(j+1,arr,current,ans,hash);
                for(k=0;k<str.length();k++){
                    hash[str[k]-'a'] = false;
                    current.pop_back();
                }
            }
        }
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        string current;
        vector<bool> hash(26,false);
        dfs(0,arr,current,ans,hash);
        return ans;
    }
};
