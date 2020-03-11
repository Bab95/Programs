class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    void printvector(vector<int>& a){
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void swapvector(vector<int>& a,vector<int>& b){
        vector<int>& c = a;
        a = b;
        b = c;
        return;
    }
    int partition(vector<vector<int> >& pairs,int start,int end){
        int pivot = pairs[start][0];
        int i = start+1;
        for(int j=start+1;j<=end;j++){
            if(pairs[j][0]<pivot){
                swap(pairs[i],pairs[j]);
                i++;
            }
        }
        swap(pairs[i-1],pairs[start]);
        return i-1;
    }
    void sortvectors(vector<vector<int> >& pairs,int start,int end){
        if(start<end){
            int pivot = partition(pairs,start,end);
            sortvectors(pairs,start,pivot-1);
            sortvectors(pairs,pivot+1,end);
        }
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(pairs.size(),1);
        int max_length = 1;
        sortvectors(pairs,0,pairs.size()-1);
        /*for(int i=0;i<pairs.size();i++){
            cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
        }*/
        for(int i=1;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]&&dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                    max_length = max(max_length,dp[i]);
                }
            }
        }
        return max_length;
    }
};
