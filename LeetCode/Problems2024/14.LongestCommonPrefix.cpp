class Solution {
public:
    string commonPrefix(string& a, string& b) {
        int i = 0;
        while (i < a.length() && i < b.length()) {
            if (a[i] != b[i]) {
                break;
            }
            i++;
        }
        return a.substr(0, i);
    } 
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size () == 1) {
            return strs[0];
        }
        string common_prefix = commonPrefix(strs[0], strs[1]);
        //cout << common_prefix << endl;
        for (int i=2;i<strs.size();i++) {
            common_prefix = commonPrefix(common_prefix, strs[i]);
            //cout << common_prefix << endl;
        }
        return common_prefix;
    }
};
