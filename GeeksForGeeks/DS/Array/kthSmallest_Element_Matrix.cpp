// Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;

// A structure to store an entry of heap.  The entry contains
// a value from 2D array, row and column numbers of the value
struct HeapNode {
    int val;  // value to be stored
    int r;    // Row number of value in 2D array
    int c;    // Column number of value in 2D array
};

// A utility function to swap two HeapNode items.
void swap(HeapNode *x, HeapNode *y) {
    HeapNode z = *x;
    *x = *y;
    *y = z;
}

// A utility function to minheapify the node harr[i] of a heap
// stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
    int l = i*2 + 1;
    int r = i*2 + 2;
    int smallest = i;
    if (l < heap_size && harr[l].val < harr[i].val)
        smallest = l;
    if (r < heap_size && harr[r].val < harr[smallest].val)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(harr, smallest, heap_size);
    }
}

// A utility function to convert harr[] to a max heap
void buildHeap(HeapNode harr[], int n)
{
    int i = (n - 1)/2;
    while (i >= 0)
    {
        minHeapify(harr, i, n);
        i--;
    }
}

#define MAX 1000
// This function returns kth smallest element in a 2D array mat[][]
int kthSmallest(int mat[MAX][MAX], int n, int k);

 int mat[MAX][MAX];

// driver program to test above function
int main()
{
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;


    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>mat[i][j];
        int r;
        cin>>r;
    cout<<kthSmallest(mat,n,r)<<endl;
}
 // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
  return 0;
}
// Driver Code Ends
/*You are required to complete this function*/
struct node{
    int data;
    int row;
    int col;
};
struct node heap[MAX];
void copy_node(struct node *tmp,struct node *heap_node){
    tmp->data = heap_node->data;
    tmp->row = heap_node->row;
    tmp->col = heap_node->col;
    return;
}
void swap_node(struct node *n1,struct node *n2){
    struct node tmp;
    tmp.data = n1->data;
    tmp.row = n1->row;
    tmp.col = n1->col;

    n1->data = n2->data;
    n1->row = n2->row;
    n1->col = n2->col;

    n2->data = tmp.data;
    n2->row = tmp.row;
    n2->col = tmp.col;
    return;
}
void restoreup(struct node heap[],int size){
    int i = size;
    int par = i/2;
    struct node k;
    copy_node(&k,&heap[size]);
    while(heap[par].data>k.data){
        copy_node(&heap[i],&heap[par]);
        i = par;
        par = i/2;
    }
    copy_node(&heap[i],&k);
    return;
}
void push_heap(int data,int row,int col,int* psize){
    *psize = *psize+1;
    heap[*psize].data = data;
    heap[*psize].row = row;
    heap[*psize].col = col;
    restoreup(heap,*psize);
}
void restoredown(struct node heap[],int size){
    struct node k;
    copy_node(&k,&heap[1]);
    int i = 1;
    int left = 2*i;
    int right = 2*i+1;
    while(right<=size){
        if(k.data<=heap[left].data&&k.data<=heap[right].data){
            copy_node(&heap[i],&k);
            return;
        }else if(heap[left].data<heap[right].data){
            copy_node(&heap[i],&heap[left]);
            i = left;
        }else{
            copy_node(&heap[i],&heap[right]);
            i = right;
        }
        left = 2*i;
        right = 2*i+1;
    }
    if(left==size&&k.data>heap[left].data){
        copy_node(&heap[i],&heap[left]);
        i = left;
    }
    copy_node(&heap[i],&k);
    return;
}
struct node delete_node(struct node heap[],int *psize){
    struct node result;
    copy_node(&result,&heap[1]);
    copy_node(&heap[1],&heap[*psize]);
    *psize = *psize-1;
    restoredown(heap,*psize);
    return result;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  if(k==0){
      return mat[0][0];
  }
  int heap_size = 0;
  heap[0].data = INT_MIN;
  heap[0].row = -1;
  heap[0].col = -1;
  for(int i=0;i<n;i++){
     push_heap(mat[i][0],i,0,&heap_size);
  }
  struct node deleted_node;
  for(int i=0;i<k;i++){
      deleted_node = delete_node(heap,&heap_size);
      if(deleted_node.col!=n-1){
          push_heap(mat[deleted_node.row][deleted_node.col+1],deleted_node.row,deleted_node.col+1,&heap_size);
      }
  }
  return deleted_node.data;
}
