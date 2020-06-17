class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> group(n,-1);
        for(int i=0;i<n;++i){
            //find min val from right for this..
            int val;
            if(group[i]!=-1){
                val = group[i];
            }else{
                val = arr[i];
            }
            //group[i] = val;
            int start = i;
            int finish;
            for(int j=n-1;j>=i;j--){
                if(arr[j]<=arr[i]){
                    finish = j;
                    break;
                }
            }
            for(int k=start;k<=finish;k++){
                group[k] = val;
            }
        }
        set<int> chunks;
        for(int i=0;i<group.size();++i){
            chunks.insert(group[i]);
        }
        return chunks.size();
    }
};
