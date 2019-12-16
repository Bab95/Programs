#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
 string substring(string s,int start,int end){
     string result;
     for(int i=start;i<=end;i++){
         result.push_back(s[i]);
     }
     return result;
 }
 int string2int(string s){
     int result = 0;
     int len = s.length();
     for(int i=0;i<len;i++){
         result = result*10+((int)s[i]-48);
     }
     return result;
 }
string timeConversion(string s) {
    /*
     * Write your code here.
     */
     string hour_string = substring(s,0,1);
     int hour = string2int(hour_string);
     if(s[8]=='P'){
         if(hour<12)
            hour+=12;
     }else if(hour==12&&s[8]=='A'){
         hour = 0;
     }
     int h1 = hour/10;
     int h2 = hour%10;
     string result;
     result.push_back(h1+48);
     result.push_back(h2+48);
     for(int i=2;i<s.length()-2;i++){
         result.push_back(s[i]);

     }
     return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
