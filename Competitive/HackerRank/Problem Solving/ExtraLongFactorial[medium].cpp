#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
typedef vector<int> bigint;
void multiply(bigint &nums1,bigint &nums2){
    vector<vector<int> > ans(nums2.size(),vector<int>());
    int carry = 0;
    for(int i=0;i<nums2.size();i++){
        carry = 0;
        int  k = i;
        while(k--){
            ans[i].push_back(0);
        }
        for(int j=0;j<nums1.size();j++){
            int num = (nums2[i])*(nums1[j])+carry;
            carry = num/10;
            num = num%10;
            ans[i].push_back(num);
        }
        if(carry!=0){
            ans[i].push_back(carry);
        }
    }
    vector<int> result;
    carry = 0;
    int sum = 0;
    for(int j=0;j<ans[ans.size()-1].size();j++){
        sum = 0;
        //carry = 0;
        for(int i=0;i<ans.size();i++){
            int num = (j>=ans[i].size())?0:ans[i][j];
            sum+=num;
        }
        sum+=carry;
        result.push_back(sum%10);
        carry = sum/10;
    }
    if(carry!=0){
        result.push_back(carry);
    }
    nums1 = result;
    /*nums1.clear();
    for(int i=result.size()-1;i>=0;i--){
        nums1.push_back(result[i]);
    }*/
}
bigint Integer(int a){
    bigint ans;
    while(a){
        int num = a%10;
        a = a/10;
        ans.push_back(num);
    }
    return ans;
}
void extraLongFactorials(int n) {
    bigint fact = Integer(1);
    for(int i=2;i<=n;i++){
        bigint j = Integer(i);
        multiply(fact,j);
    }
    for(int i=fact.size()-1;i>=0;i--){
        cout<<fact[i];
    }
    cout<<endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
