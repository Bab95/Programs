class Solution {
public:
    string defangIPaddr(string address) {
        vector<char> resVec;
        string result;
        int k = 0;
        int i = 0;
        for(i=0;i<address.length();i++){
            if(address[i]=='.'){
                result = result+address.substr(i-k,k);
                result = result+"[.]";
                k = 0;
                continue;
            }
            k++;
        }
        result = result+address.substr(i-k,k);
        //string result(resVec);
        return result;
    }
};
