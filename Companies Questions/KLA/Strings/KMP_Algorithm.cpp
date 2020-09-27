#include <bits/stdc++.h>
using namespace std;
class KMP{
    public:
        void kpm_algorithm(string str,string pattern){
            /*building a table of longest suffix which is also a prefix*/
            /*
            * Build table for pattern string which will tell where to start comparing on a mismatch
            * We need to find longest suffix which is also a prefix.
            * So when a mismatch happens at i look at table[i-1] and move the pointer to table[i-1] position and start
            * Comparing from there.*/
            int p = pattern.length();
            int len = str.length();
            vector<int> table(p);
            int i = 0;
            int j = i+1;
            table[i] = 0;
            while(j<p){
                if(pattern[i]==pattern[j]){
                    table[j] = i+1;
                    ++i;
                    ++j;
                }else{
                    if(i>0){
                        i = table[i-1];
                    }else{
                        //no suffix found which is also a prefix as we are looking at start........
                        table[j] = 0;
                        j++;
                    }
                }
            }

            /*Matching actual string it is almost similar to building pattern*/
            int index = 0;
            j = 0;
            int result_index = -1;
            while(index<len){
                if(str[index]==pattern[j]){
                    index++;
                    j++;
                }
                if(j==p){
                    result_index = i-p;
                    cout<<"string found at index::::"<<result_index<<endl;
                    return;
                }
                else if(index<len&&pattern[j]!=str[index]){
                    /*again two cases either we are at start or in between
                    *if we are at start there's no meaning just move on
                    * if we are in between and matched some pattern already move to longest suffix prefix's just next
                    * as we have already matched till that point
                    */
                   if(j==0){
                       index++;
                   }else{
                       j = table[j-1];
                   }
                }
            }
        }
};