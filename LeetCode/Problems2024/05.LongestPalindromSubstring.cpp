class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        /*if (s.length() == 2) {
            if (s[0] == s[1]) {
                return s;
            }
            else {
                return s.substr(0, 1);
            }
        }*/
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int max_length = 1;
        int start_index = 0;
        for (int i=1;i<n;i++) {
            if (s[i] == s[i-1]) {
                dp[i-1][i] = 2;
                max_length = 2;
                start_index = i-1;
            }
            dp[i][i] = 1;
        }

        for (int length = 3;length <= n;length++) {
            for (int i = 0;i < n - length + 1;i++) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i+1][j-1] > 0) {
                    dp[i][j] = length;
                    if (max_length < length) {
                        max_length = length;
                        start_index = i;
                    }        
                }
            }
        }

        /*for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cout << dp[i][j] <<" ";
            }
            cout << endl;
        }*/

        return s.substr(start_index, max_length);
    }
};
