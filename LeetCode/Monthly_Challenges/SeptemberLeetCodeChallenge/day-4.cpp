class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> labels;
        int i = 0;
        unordered_map<char,int> mmap;
        for(i=0;i<S.length();++i){
            mmap[S[i]] = i;
        }
        unordered_set<char> sset;
        i = 0;
        while(i<S.length()){
            char current = S[i];
            int last_index = mmap[current];
            int current_len = last_index - i + 1;
            for(int j=i+1;j<=last_index&&j<S.length();++j){
                if(mmap[S[j]]>last_index){
                    last_index = mmap[S[j]];
                    current_len = max(current_len,last_index-i+1);
                }
            }
            labels.push_back(current_len);
            i = last_index + 1;
        }
        return labels;
    }
};
