class Solution {
public:
    int fact(int n){
        vector<int> factorial(n+1,1);
        factorial[0] = 1;
        factorial[1] = 1;
        for(int i=2;i<=n;++i){
            factorial[i] = factorial[i-1]*i;
        }
        return factorial[n];
    }
    void calculate_Permutation(vector<int>& str){
        //int i = str.size()-1;
        int j = str.size()-1;
        for(j=str.size()-1;j>0;j--){
            if(str[j]>str[j-1]){
                break;
            }
        }
        if(j==0){
            return;
        }

        int x = str[j-1],smallest = j;
        for(int i=j+1;i<str.size();++i){
            if(str[i]>x&&str[i]<str[smallest]){
                smallest = i;
            }
        }
        swap(str[j-1],str[smallest]);
        sort(str.begin()+j,str.end());

    }
    void permute(vector<int>& str,int k){
        int n = str.size();
        int N = fact(n);
        for(int i=1;i<=N;++i){
            if(i==k){
                return;
            }
            calculate_Permutation(str);
        }
    }
    string getPermutation(int n, int k) {
        vector<int> str(n);
        for(int i=0;i<n;++i){
            str[i] = i+1;
        }
        permute(str,k);
        string ans;
        for(auto i : str){
            ans.push_back((char)i+'0');
        }
        return ans;
    }
};

///Optimzed....
class Solution2 {
public:
    void factorial(int n,vector<int>& fact){
        fact[0] = 1;
        fact[1] = 1;
        for(int i=2;i<=n;++i){
            fact[i] = fact[i-1]*i;
        }
    }
    void calculate_permutation(vector<int>& perm,int n,int k,string& ans,vector<int>& fact){
        if(n==1){
            ans.push_back(perm[0]+'0');
            return;
        }
        int index = k/fact[n-1];
        if(k%fact[n-1]==0){
            index--;
        }
        ans.push_back(perm[index]+'0');
        perm.erase(perm.begin()+index);
        k-=fact[n-1]*index;
        calculate_permutation(perm,n-1,k,ans,fact);
    }
    string getPermutation(int n, int k) {
        vector<int> perm(n);
        vector<int> fact(n+1,1);
        factorial(n,fact);
        for(int i=0;i<n;++i){
            perm[i] = i+1;
        }
        string ans;
        calculate_permutation(perm,n,k,ans,fact);
        return ans;
    }
};
