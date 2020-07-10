class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(words.count(endWord)==0){
            return 0;
        }
        unordered_set<string> visited;
        unordered_set<string> left,right;
        int ans = 1;
        left.insert(beginWord);
        right.insert(endWord);
        int len = beginWord.length();
        while(!left.empty()){
            unordered_set<string> current;
            for(auto it=left.begin();it!=left.end();++it){
                string w = *it;
                if(right.find(w)!=right.end()){
                    return ans;
                }
                visited.insert(w);
                for(int i=0;i<len;++i){
                    char tmp = w[i];
                    for(char c='a';c<='z';++c){
                        w[i] = c;
                        if(words.find(w)!=words.end()&&visited.find(w)==visited.end()){
                            current.insert(w);
                        }
                    }
                    w[i] = tmp;
                }
            }
            ans++;
            if(right.size()<current.size()){
                left = right;
                right = current;
            }else{
                left = current;
            }
        }
        cout<<"---"<<endl;
        return 0;
    }
};
