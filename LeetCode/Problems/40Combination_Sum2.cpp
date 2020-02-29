class Solution {
public:
    void generate(vector<vector<int> >& result,unordered_map<int,int>& m,vector<int>& tmp,int k,int target,int sum){
        if(sum==target){
            result.push_back(tmp);
            return;
        }
        int i = 0;
        for(unordered_map<int,int>::iterator itr=m.begin();itr!=m.end();itr++,i++){
            if(i<k||itr->second<=0||sum+itr->first>target){
                continue;
            }
            tmp.push_back(itr->first);
            sum = sum+itr->first;
            itr->second--;
            if(itr->second==0){
                generate(result,m,tmp,i+1,target,sum);
            }else{
                generate(result,m,tmp,i,target,sum);
            }
            tmp.pop_back();
            sum = sum-itr->first;
            itr->second++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> tmp;
        unordered_map<int,int> m;
        for(int i=0;i<candidates.size();i++){
            m[candidates[i]]++;
        }
        generate(result,m,tmp,0,target,0);
        return result;
    }
};
