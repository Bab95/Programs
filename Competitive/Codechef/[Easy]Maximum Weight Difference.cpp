#include <iostream>

using namespace std;
void swap(long long int *a,long long int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
long long int max(long long int a,long long int b){
	return a>=b?a:b;
}
int partition(long long int arr[],int low,int high){
	long long int pivot = arr[high];
	int i = low-1;
	for(int j = low;j<=high;j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}
void quicksort(long long int arr[],int low,int high){
	if(low<high){
		int pivot = partition(arr,low,high);
		quicksort(arr, low, pivot-1);
		quicksort(arr, pivot+1, high);
	}
}
int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		long long int arr[n];
		long long int res = 0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			res+=arr[i];
		}
		quicksort(arr, 0, n-1);
		long long int temp = 0,tmp = 0;
		for(int i = 0;i<k;i++){
			temp+=arr[i];//first k
			tmp+=arr[n-1-i];//last k
		}
		long long int r1 = res-2*temp;
		long long int r2 =  res-tmp;
		res = max(r1,tmp-r2);
		cout<<res<<endl;

	}
}
