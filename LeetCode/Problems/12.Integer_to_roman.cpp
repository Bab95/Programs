class Solution {
public:
    string intToRoman(int num) {
        int arbics[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string romans[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string result = "";
        int size = sizeof(arbics)/sizeof(int);
        for(int i=0;i<size;i++){
            while(num-arbics[i]>=0){
                result.append(romans[i]);
                num = num-arbics[i];
            }
        }
        return result;
    }
};
