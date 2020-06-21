class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> mmap;
        for(int i=0;i<S.length();++i){
            mmap[S[i]] = i;
        }
        for(char c='a';c<='z';++c){
            if(mmap.find(c)==mmap.end()){
                mmap[c] = S.length()+1;
            }
        }
        /*for(auto it:mmap){
            cout<<it.first<<" : "<<it.second<<endl;
        }*/
        int n = T.length();
        bool flag = false;
        for(int i=0;i<n-1;++i){
            for(int j=0;j<n-i-1;++j){
                if(mmap[T[j]]>mmap[T[j+1]]){
                    swap(T[j],T[j+1]);
                    flag = true;
                }
            }
            if(!flag){
                break;
            }
        }
        return T;
    }
};
