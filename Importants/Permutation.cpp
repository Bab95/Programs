#include <iostream>
using namespace std;
int main(){
	int num;
	cin>>num;
	int A[num];
	for(int i=0;i<num;i++){
		A[i] = i;
	}
	int currentIndex = num;
	int index = 1;
	while(A[0]<num){
		if(currentIndex==num){
			cout<<index<<": ";
			index++;
			for(int j=0;j<num;j++){
				cout<<A[j]+1;
			}
			cout<<endl;
			A[num-1]++;
			currentIndex = num-1;
		}

		if(A[currentIndex]==num){
			A[currentIndex] = 0;
			currentIndex--;
			A[currentIndex]++;
		}else{
			int j;
			for(j=0;j<currentIndex;j++){
				if(A[currentIndex]==A[j]){
					A[currentIndex]++;
					break;
				}
			}
			if(j==currentIndex){
				currentIndex++;
			}
		}

	}
}
