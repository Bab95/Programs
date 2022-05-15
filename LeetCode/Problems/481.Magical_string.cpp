class Solution {
public:
    string getString(char c,int count){
        string str;
        int counter = 0;
        while (counter < count){
            str.push_back(c);
            counter++;
        }
        return str;
    }
    int stoi(char c){
        if (c=='1'){
            return 1;
        }
        return 2;
    }
    char getRev(char c){
        if (c == '1'){
            return '2';
        }
        return '1';
    }
    int magicalString(int n) {
        if (n<=3){
            return 1;
        }
        string str = "122";
        int pointer = 2;
        int current = 3;
        bool flag = true;
        int ans = 0;
        while (current <= n){
            int count = stoi(str[pointer]);
            pointer++;
            current += count;
            if (flag){
                str += getString('1', count);
            } else {
                str += getString('2', count);
            }
            flag = !flag;
        }
        //cout <<str<<endl;
        for (int i=0;i<n;i++){
            if (str[i] == '1'){
                ans++;
            }
        }
        return ans;
    }
};

/*

122112122122112112212112122112112122122112

12211221211221221211221221121121221121122

1221121221221121122121121221

122

12

*/
