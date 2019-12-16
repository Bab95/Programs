#include <iostream>
using namespace std;
bool isvalid(int key){
	if (key <= 26)
		return true;
	return false;
}
int str_length(char *arr){
	int result = 0;
	for (int i = 0; arr[i] != '\0'; i++){
		result++;
	}
	return result;
}
int solve(char *input,int n){
	/*
	if (((int)input[0]-48 > 2 )&& ((int)input[1]-48 == 0)){
		return 0;
	}*/
	int solution[5001];
	solution[0] = 1;
	solution[1] = 1;
	for (int i = 2; i<=n; i++){
		int prev = (int)input[i - 2]-48;
		int current = (int)input[i-1]-48;
		if (current != 0 && prev == 0){
			solution[i] = solution[i - 1];
		}
		else if (current == 0 && isvalid(prev * 10 + current)){
			solution[i] = solution[i - 2];
		}
		else if (current == 0 && !isvalid(prev * 10 + current)){
			return 0;
		}
		else if (!isvalid(prev * 10 + current)){
			solution[i] = solution[i - 1];
		}
		else{
			solution[i] = solution[i - 1] + solution[i - 2];
		}
	}
	return solution[n];
}
int main(){
	char input[5001];
	while (1){
		cin >> input;
		if (input[0] == '0')
			break;
		int n = str_length(input);
		cout << solve(input,n)<<endl;
	}
	//system("pause");
} 
