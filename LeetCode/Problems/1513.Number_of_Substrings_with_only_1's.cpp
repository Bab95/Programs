#define M 1000000007
class Solution {
public:
    int numSub(string s) {
        s.push_back('0');
        int start = -1;
        unsigned long long int ans = 0;
        int i = 0;
        while(i<s.length()){
            if(s[i]=='0'){
                if(start!=-1){ //its an end....
                    unsigned long long int len = (unsigned long long int)(i-start);
                    cout<<len<<endl;
                    long long int current=0;
                    if(len%2==0){
                        current = len/2;
                        current = current*(len+1);
                        //current = ((current%M)*(len+1))%M;
                    }else{
                        current = (len+1)/2;
                        current = current*len;
                        //current = ((current%M)*(len))%M;
                    }
                    //ans = ans%M+current%M;
                    //ans = ans%M;
                    ans+=current;
                    start = -1;
                }
            }else{
                if(start==-1){
                    start = i;
                }
            }
            ++i;
        }
        cout<<ans<<endl;
        ans = ans%M;
        return (int)ans;
    }
};
