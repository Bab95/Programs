#include <bits/stdc++.h>

using namespace std;
#define MAX_SIZE 100001
// Complete the candies function below.
int forward_array[MAX_SIZE];
int backward[MAX_SIZE];
long candies(int n, vector<int> arr) {
    forward_array[0] = 1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            forward_array[i] = forward_array[i-1]+1;
        }else{
            forward_array[i] = 1;
        }

    }
    backward[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1]){
            backward[i] = backward[i+1]+1;
        }else{
            backward[i] = 1;
        }
    }
    long int result = 0;
    for(int i=0;i<n;i++){
        result+=max(forward_array[i],backward[i]);
    }
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
