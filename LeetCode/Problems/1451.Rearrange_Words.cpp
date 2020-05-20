class Solution {
public:
    static bool compare(string& s1,string& s2){
        if(s1.length()>s2.length()){
            return false;
        }
        return true;
    }
    void to_lower_case(string& s){
        for(int i=0;i<s.length();++i){
            if(s[i]>='A'&&s[i]<='Z'){
                s[i] = s[i]-'A'+'a';
            }
        }
    }
    void camelcase(string& s){
        s[0] = s[0]-'a'+'A';
    }
    void merge(vector<string>& arr,int l,int m,int r,vector<string>& tmp){
        /*cout<<"merge ";
        cout<<l<<" "<<m<<" "<<r<<endl;
        */
        int i = l,j = m,k=l;
        //vector<string> tmp(arr.size());
        while(i<m&&j<=r){
            if(compare(arr[i],arr[j])){
                tmp[k++] = arr[i++];
            }else{
                tmp[k++] = arr[j++];
            }
        }
        while(i<m){
            tmp[k++] = arr[i++];
        }
        while(j<=r){
            tmp[k++] = arr[j++];
        }
        for(int i=l;i<=r;++i){
            arr[i] = tmp[i];
        }
    }
    void merge_sort(vector<string>& arr,int l,int r,vector<string>& tmp){
        /*cout<<"merge_sort ";
        cout<<l<<" "<<r<<endl;
        */
        if(l<r){
            int m = (l+r)/2;
            merge_sort(arr,l,m,tmp);
            merge_sort(arr,m+1,r,tmp);
            merge(arr,l,m+1,r,tmp);
        }
    }
    string arrangeWords(string text) {
        stringstream ss(text);
        vector<string> vec;
        string word;
        while(ss>>word){
            to_lower_case(word);
            vec.push_back(word);
        }
        vector<string> tmp(vec.size());
        merge_sort(vec,0,vec.size()-1,tmp);
        string ans;
        camelcase(vec[0]);
        for(int i=0;i<vec.size();++i){
            ans.append(vec[i]);
            ans.push_back(' ');
        }
        if(ans.length()!=0){
            ans.pop_back();
        }
        /*for(int i=0;i<vec.size();++i){
            cout<<vec[i]<<" ";
        }*/
        return ans;
    }
};
