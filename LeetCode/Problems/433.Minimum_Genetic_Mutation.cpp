class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> start_set;
        unordered_set<string> end_set;
        unordered_set<string> bank_set;
        bank_set.insert(bank.begin(),bank.end());
        if(bank_set.count(end)==0){
            return -1;
        }
        start_set.insert(start);
        end_set.insert(end);
        int mutation = 0;
        int len = start.length();

        string possible = "ACGT";

        while(!start_set.empty()&&!end_set.empty()){
            cout<<"here";
            mutation++;
            if(start_set.size()>end_set.size()){
                swap(start_set,end_set);
            }
            unordered_set<string> current;
            for(string s : start_set){

                for(int i=0;i<len;++i){
                    char tmp = s[i];
                    for(int j=0;j<possible.length();++j){
                        s[i] = possible[j];
                        if(end_set.count(s)){
                            return mutation;
                        }
                        if(bank_set.count(s)){
                            bank_set.erase(s);
                            current.insert(s);
                        }
                    }
                    s[i] = tmp;
                }
            }
            start_set = current;
        }
        return -1;
    }
};
