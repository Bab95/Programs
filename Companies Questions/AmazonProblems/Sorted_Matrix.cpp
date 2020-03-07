#define MAT_SIZE 100
using namespace std;
struct heapnode{
	int data;
	int row;
	int col;
};
struct point{
		int data;
		int row;
		int col;
};
struct heapnode heap[MAX_SIZE];
void insert(int data,int p,int j,int *heapsize){
		*heapsize = *heapsize + 1;
		heap[*heapsize].data = data;
		heap[*heapsize].row = p;
		heap[*heapsize].col = j;

		int i = *heapsize;
		int par = i/2;
		struct heapnode k;
		k.data = heap[i].data;
		k.row = heap[i].row;
		k.col = heap[i].col;
		while(heap[par].data>k.data){
				heap[i].data = heap[par].data;
				heap[i].row = heap[par].row;
				heap[i].col = heap[par].col;
				i = par;
				par = i/2;
		}
		heap[i].data = k.data;
		heap[i].row = k.row;
		heap[i].col = k.col;
}
void restoredown(int heapsize){
		int i = 1;
		int left = 2*i,right = 2*i + 1;
		struct heapnode k;
		k.data = heap[i].data;
		k.row = heap[i].row;
		k.col = heap[i].col;
		while(right<=heapsize){
				if(k.data<=heap[left].data&&k.data<=heap[right].data){
						heap[i].data = k.data;
						heap[i].row = k.row;
						heap[i].col = k.col;
						return;
				}else if(heap[left].data<heap[right].data){
						heap[i].data = heap[left].data;
						heap[i].row = heap[left].row;
						heap[i].col = heap[left].col;
						i = left;
				}else{
						heap[i].data = heap[right].data;
						heap[i].row = heap[right].row;
						heap[i].col = heap[right].col;
						i = right;
				}
				left = 2*i;
				right = 2*i + 1;
		}
		if(left==heapsize&&k.data>=heap[left].data){
				heap[i].data = heap[left].data;
				heap[i].row = heap[left].row;
				heap[i].col = heap[left].col;
				i = left;
		}
		heap[i].data = k.data;
		heap[i].row = k.row;
		heap[i].col = k.col;
		return;
}
struct point heap_delete(int *heapsize){
		struct point p;
		p.data = heap[1].data;
		p.row = heap[1].row;
		p.col = heap[1].col;
		heap[1].data = heap[*heapsize].data;
		heap[1].row = heap[*heapsize].row;
		heap[1].col = heap[*heapsize].col;
		*heapsize = *heapsize - 1;
		restoredown(*heapsize);
		return p;
}
/*
void printmatrix(int mat[][MAT_SIZE],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}*/
int main() {
	//freopen("mat_input.txt","r",stdin);
		heap[0].data = INT_MIN;
		heap[0].row = -1;
		heap[0].col = -1;
		int mat[MAT_SIZE][MAT_SIZE];
		int t,n;
		cin>>t;
		while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>mat[i][j];
			}
		}
		//printmatrix(mat,n);
		int j = 0,heapsize = 0;
		for(int i=0;i<n;i++){
			insert(mat[i][j],i,j,&heapsize);
		}
		for(int i=0;i<n*n;i++){
			struct point p = heap_delete(&heapsize);
			cout<<p.data<<" ";
			if(p.col==n-1){
				continue;
			}
			else{
				insert(mat[p.row][p.col+1],p.row,p.col+1,&heapsize);
			}
		}
		cout<<endl;
		}
	return 0;
}
