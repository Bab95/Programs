class Solution {
public:
    vector<int> splitcomplex(string& a){
        string real;
        int i = 0;
        while(i<a.length()&&a[i]!='+'){
            real.push_back(a[i]);
            ++i;
        }
        ++i;
        string img;
        while(i<a.length()){
            img.push_back(a[i]);
            ++i;
        }
        cout<<real<<endl<<img<<endl;
        vector<int> ans(2);
        ans[0] = stoi(real);
        ans[1] = stoi(img);
        return ans;
    }
    string complexNumberMultiply(string a, string b) {
        vector<int> c1 = splitcomplex(a);
        vector<int> c2 = splitcomplex(b);
        int real = c1[0]*c2[0]-(c1[1]*c2[1]);
        int img = (c1[1]*c2[0])+(c1[0]*c2[1]);
        string ans;
        ans.append(to_string(real));
        ans.push_back('+');
        ans.append(to_string(img));
        ans.push_back('i');
        return ans;
    }
};
