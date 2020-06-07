class Solution {
public:
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        unordered_map<int,char> mmap;
        for(int i=0;i<=9;++i){
            mmap[i] = i+'0';
        }
        for(int i=10;i<=15;++i){
            mmap[i] = 'a'+i-10;
        }
        string ans;
        if(num<0){
            //two's complement.....
            long int n = ((long int)pow(2,32) - (long int)abs(num));
            cout<<n<<endl;
            while(n){
                int rem = n%16;
                ans.push_back(mmap[rem]);
                n = n/16;
            }
        }else{
            while(num){
                int rem = num%16;
                ans.push_back(mmap[rem]);
                num = num/16;
            }
        }
        int l = 0;
        int r = ans.length()-1;
        while(l<r){
            char tmp = ans[l];
            ans[l] = ans[r];
            ans[r] = tmp;
            ++l;
            --r;
        }
        return ans;
    }
};
