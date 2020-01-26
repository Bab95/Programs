#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *left, *right;
};
struct node *getnode(int data){
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;
    return tmp;
}
int findIndex(int arr[],int val,int n){
  for(int i=0;i<n;i++){
    if(arr[i]==val){
      return i;
    }
  }
  return -1;
}
void printPostOrder(int [],int pre[],int n){
  int index = findIndex(in,pre[0],n);
  if(index!=0){
    printPostOrder(in,pre+1,index);
  }
  if(index!=n-1){
    printPostOrder(in+index+1,pre+index+1,n-index-1);
  }
  cout<<pre[0]<<" ";
}
void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
int partition(int arr[],int start,int end){
  int pivot = arr[start];
  int i = start+1;
  for(int j=start+1;j<=end;j++){
    if(arr[j]<pivot){
      swap(&arr[i],&arr[j]);
      i++;
    }
  }
  swap(&arr[i-1],&arr[start]);
  return i-1;
}
void quicksort(int arr[],int start,int end){
  if(start<end){
    int pivot = partition(arr,start,end);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);
  }
}
int main() {
	//code
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int pre[n],in[n];
    for(int i=0;i<n;i++){
      cin>>pre[i];
      in[i] = pre[i];
    }
    quicksort(in,0,n-1);
    printPostOrder(in,pre,n);
  }
	return 0;
}
