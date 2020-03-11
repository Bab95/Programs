#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
int mybinarySearch(vector<int>& score_map,int low,int high,int target){
    if(low>high){

    }
    if(target>=score_map[low]){
        int res = low+1;
        return res;
    }else if(target<=score_map[high]){
        int res = (target==score_map[high])?(high+1):high+2;
        return res;
    }
    int mid = (low+high)/2;
    if(target==score_map[mid]){
        return mid+1;
    }else if(target>score_map[mid]){
        return mybinarySearch(score_map,low,mid-1,target);
    }else{
        return mybinarySearch(score_map,mid+1,high,target);
    }
    return -1;
}
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    /*unordered_set<int> scoremap;
    for(int i=0;i<scores.size();i++){
        scoremap.insert(scores[i]);
    }*/
    vector<int> score_map;
    for(int i=0;i<scores.size();){
        score_map.push_back(scores[i++]);
        while(i<scores.size()&&scores[i]==scores[i-1]){
            i++;
        }
    }
    /*for(int i=0;i<score_map.size();i++){
        cout<<score_map[i]<<" ";
    }*/
    vector<int> result(alice.size(),0);
    for(int i=0;i<alice.size();i++){
        /*if(alice[i]>=score_map[0]){
            result[i] = 1;
        }else if(alice[i]==score_map[score_map.size()-1]){
            result[i] = score_map.size();
        }else if(alice[i]<score_map[score_map.size()-1]){
            result[i] = score_map.size()+1;
        }else{*/
            result[i] = mybinarySearch(score_map,0,score_map.size()-1,alice[i]);
        //}

    }
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
