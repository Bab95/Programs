class Solution {
public:
    int find_end_index(string& s,int start){
        int ans = -1;
        for(int i=start+1;i<s.length();++i){
            if(s[i]==s[start]){
                ans = max(ans,i);
            }
        }
        return ans;
    }
    vector<int> partitionLabels(string s) {
        int start = 0;
        vector<int> ans;
        while(start<s.length()){
            //cout<<start<<" : ";
            int end = find_end_index(s,start);
            //cout<<end<<endl;
            if(end==-1){
                ans.push_back(1);
                start++;
            }else{
                unordered_set<char> sset;
                int len = end-start+1;
                for(int i=start;i<=end;++i){
                    sset.insert(s[i]);
                }
                int prev_ = end+1;
                for(int i=end+1;i<s.length();++i){
                    if(sset.count(s[i])!=0){
                        for(int j=prev_;j<s.length()&&j<=i;++j){
                            sset.insert(s[j]);
                        }
                        prev_ = i+1;
                        len = max(len,i-start+1);
                        end = max(i,end);
                    }
                }
                ans.push_back(len);
                start = end+1;
            }
        }
        return ans;
    }
};
/*
"eaaaabaaec"
"ababcbacadefegdehijhklij"
"abbcbcdefegdehijhklij"
*/
