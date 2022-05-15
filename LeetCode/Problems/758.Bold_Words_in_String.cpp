class Solution{
public:
    int get_index(string& needle, string& haystack) {
        size_t pos = haystack.find(needle);
        if (pos != string::npos) {
            return (int)pos;
        }
        return -1;
    }
    string bold_words(vector<string>& words, string str) {
        vector<bool> marked(str.length(), false);
        for (int i = 0; i < words.size(); i++) {
            int index = get_index(words[i], str);
            if (index != -1) {
                for (int p = 0; p < words[i].length(); p++) {
                    marked[index + p] = true;
                }
            }
        }
        string result = "";
        for (int i = 0; i < str.length(); ) {
            if (marked[i]) {
                result += "<b>";
                while (i < str.length() && marked[i]) {
                    result.push_back(str[i]);
                    i++;
                }
                result += "</b>";
            }
            else {
                result.push_back(str[i]);
                i++;
            }
        }
        return result;
    }
};