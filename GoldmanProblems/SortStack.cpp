#include<bits/stdc++.h>
using namespace std;
class SortedStack{
public:
	stack<int> s;
	void sort();
};
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("
");
}
int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s
you are required to complete the below method */
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
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
void SortedStack :: sort()
{
   //Your code here
   int n = s.size();
   int arr[n];
   int i = 0;
   while(!s.empty()){
       arr[i++] = s.top();
       s.pop();
   }
   quicksort(arr,0,n-1);
   for(int i=0;i<n;i++){
       s.push(arr[i]);
   }
}
