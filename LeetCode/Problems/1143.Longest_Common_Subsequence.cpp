class Solution {
public:
    int table[1001][1001];
    int max(int a,int b,int c){
        int tmp = a>b?a:b;
        return tmp>c?tmp:c;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    table[i][j] = 0;
                }else if(text1[i-1]==text2[j-1]){
                    table[i][j] = 1+table[i-1][j-1];
                }else{
                    table[i][j] = max(table[i-1][j],table[i][j-1],table[i-1][j-1]);
                }
            }
        }
        return table[m][n];
    }
};
