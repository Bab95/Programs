class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n = cards.size();
       vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = cards[0];
        right[n-1] = cards[n-1];
        for(int i=1;i<n;++i){
            left[i] = left[i-1]+cards[i];
        }
        for(int i=n-2;i>=0;--i){
            right[i] = right[i+1]+cards[i];
        }
        /*for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;++i){
            cout<<right[i]<<" ";
        }*/
        int score = 0;
        //cout<<endl;
        int l = 0;
        int r = n-k+1;
        while(l<k&&r<n){
            int current = left[l] + right[r];
            //cout<<l<<" "<<r<<" "<<current<<endl;
            score = max(score,current);
            ++l;
            ++r;
        }
        int boundary = max(left[k-1],right[n-k]);
        score = max(boundary,score);
        return score;
    }

};
