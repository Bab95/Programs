#include <iostream>
#define msize 10000
#define INT_MAX 999999
using namespace std;
int heap[msize];

void swapm(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void restoredown(int heap[],int i,int size){
	int left = 2*i;
	int right = 2*i+1;
	int num = heap[i];
	while(right<=size){
		if(num>=heap[left]&&num>=heap[right]){
			heap[i] = num;
			return;
		}else if(heap[left]>heap[right]){
			heap[i] = heap[left];
			i = left;
		}else{
			heap[i] = heap[right];
			i = right;
		}
		left = 2*i;
		right = 2*i+1;
	}
	if(left==size&&num<heap[left]){
		heap[i] = heap[left];
		i = left;
	}
	heap[i] = num;
}
void restoreup(int heap[],int i){
	int k = heap[i];
	int par = i/2;
	while(heap[par]<k){
		heap[i] = heap[par];
		i = par;
		par = i/2;
	}
	heap[i] = k;
}
int delete_heap(int heap[],int *psize){
	int hsize = *psize;
	swapm(&heap[1],&heap[hsize]);
	hsize--;
	restoredown(heap, 1, hsize);
	*psize = hsize;
	return heap[hsize+1];
}
void insert_heap(int heap[],int num,int *psize){
	int i = *psize;
	heap[i++] = num;
	*psize = i;
	restoreup(heap,i-1);
}
int main(int argc, char *argv[]) {
	int tmp;
	int n;
	int hsize = 1;
	heap[0] = INT_MAX;
	freopen("heap_input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		insert_heap(heap,tmp,&hsize);
	}
	for(int i=1;i<=n;i++){
		cout<<delete_heap(heap,&hsize)<<endl;
	}

}
