class Solution {
public:
    /*[3,1,2,4,4,4,5,4,7,9]*/
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int> groups(n,-1);
        int group_counter = 0;
        for(int i=0;i<n;++i){
            int val;
            if(groups[i]==-1){
                val = group_counter++;
            }else{
                val = groups[i];
            }
            int start = i;
            int finish = i;
            for(int j=n-1;j>=i;j--){
                if(arr[j]<arr[i]){
                    finish = j;
                    break;
                }
            }
            for(int k=start;k<=finish;++k){
                groups[k] = val;
            }
        }

        set<int> chunks;
        for(int i:groups){
            chunks.insert(i);
            //cout<<i<<" ";
        }
        //cout<<endl;
        return chunks.size();
    }
};
