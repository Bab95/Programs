class Solution {
public:
    int getCount(string& domain){
        stringstream streamobj;
        int count;
        string str = "";
        int i = 0;
        while (i < domain.length() && domain[i] != ' '){
            str.push_back(domain[i]);
            i++;
        }
        streamobj << str;
        streamobj >> count;
        return count;
    }
    string get_domain(string& str){
        int i = 0;
        while (i < str.length() && str[i] != ' '){
            i++;
        }
        return str.substr(i+1, str.length()-i-1);
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domain_visit_count;
        vector<string> result;
        for (int i=0;i<cpdomains.size();i++){
            int count = getCount(cpdomains[i]);
            int j = 0;
            string domain = get_domain(cpdomains[i]);
            domain_visit_count[domain] += count;
            
            while (j<domain.length()){
                if (domain[j] == '.'){
                    domain_visit_count[domain.substr(j+1, domain.length()-j-1)] += count;
                }
                j++;
            }
        }
        /*for (auto it=domain_visit_count.begin();it!=domain_visit_count.end();it++){
            cout << it->first << " " << it->second << endl;
        }*/
        for (auto it=domain_visit_count.begin();it!=domain_visit_count.end();it++){
            result.push_back(to_string(it->second) + " " + it->first);
        }
        return result;
    }
};