class Solution {
public:
    string multiply(string num1, string num2) {
        /*int l = 0;
        int r = num1.size()-1;
        while(l<r){
            char tmp = num1[l];
            num1[l] = num1[r];
            num1[r] = tmp;
            l++;
            r--;
        }
        l = 0;
        r = num2.size()-1;
        while(l<r){
            char tmp = num2[l];
            num2[l] = num2[r];
            num2[r] = tmp;
            l++;
            r--;
        }
        int carry = 0;
        string result;
        l = 0;
        r = 0;
        while(l<num1.size()||r<num2.size()){
            int n1 = (l==num1.size())?-1:((int)num1[l]-48);
            int n2 = (r==num2.size())?-1:((int)num2[r]-48);
            int mul =
        }*/
        vector<vector<int> > result;
        int s1 = num1.size();
        int s2 = num2.size();
        string tmp;
        int t_size;
        if(s1<s2){
            tmp = num1;
            num1 = num2;
            num2 = tmp;
            s1 = num1.size();
            s2 = num2.size();
        }
        vector<int> res;
        /*for(int i=0;i<s2;i++){
            result.push_back(res);
        }*/
        for(int i=num2.size()-1,k=0;i>=0;i--,k++){
            int carry = 0;
            int t = k;
            while(t--){
                res.push_back(0);
            }
            int n2 = (int)num2[i]-48;
            for(int j=num1.size()-1;j>=0;j--){
                int n1 = (int)num1[j]-48;
                int mul = n1*n2+carry;
                carry = mul/10;
                mul = mul-(mul/10)*10;
                res.push_back(mul);
            }
            if(carry!=0){
                res.push_back(carry);
            }
            result.push_back(res);

            /*for(int i=res.size()-1;i>=0;i--){
                cout<<res[i]<<" ";
            }
            cout<<endl;
            */
            res.clear();
        }
        int row = result.size();
        int col = result[row-1].size();

        //cout<<"col_val: "<<col<<endl;

        string final_result;
        int carry = 0;
        for(int i=0;i<col;i++){
            int sum = carry;
            for(int j=0;j<row;j++){
                if(i<=result[j].size()-1){
                    sum+=result[j][i];
                }
            }
            carry = sum/10;
            sum = sum-(sum/10)*10;
            final_result.push_back((char)(sum+48));
        }
        if(carry!=0){
            final_result.push_back((char)(carry+48));
        }
       /* cout<<"final_result: ";
        cout<<final_result<<endl;*/

        int l = 0;
        int r = final_result.size()-1;
        if(final_result[r]=='0'){
            while(r>0&&final_result[r]=='0'){
                final_result.pop_back();
                r--;
            }
        }
        while(l<r){
            char tmp = final_result[l];
            final_result[l] = final_result[r];
            final_result[r] = tmp;
            l++;
            r--;
        }
        return final_result;
    }
};
