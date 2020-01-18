#include <iostream>
#define MAX_SIZE 1000001
#define <limits.h>
using namespace std;
int max_heap[MAX_SIZE];
int min_heap[MAX_SIZE];
void copy(int *a,int *b){
    *a = *b;
    return;
}
void intilialize_heap(int min_heap[],int max_heap[]){
    min_heap[0] = INT_MIN;
    max_heap[0] = INT_MAX;
}
bool is_empty(int *psize){
    if(*psize==0){
        return true;
    }
    return false;
}
void restore_min_up(int heap[],int size){
    int i = size;
    int par = i/2;
    int k = heap[size];
    while(k<heap[par]){
        copy(&heap[i],&heap[par]);
        i = par;
        par = i/2;
    }
    copy(&heap[i],&k);
}
int push_min_heap(int heap[],int data,int *psize){
    *psize = *psize+1;
    heap[*psize] = data;
    restore_min_up(heap,*psize);
}
void restore_min_down(int heap[],int i,int size){
    int k = heap[i];
    int left = 2*i;
    int right = 2*i+1;
    while(right<=size){
        if(k<=heap[left]&&k<=heap[right]){
            copy(&heap[i],&k);
            return;
        }else if(heap[left]<heap[right]){
            copy(&heap[i],&heap[left]);
            i = left;
        }else{
            copy(&heap[i],&heap[right]);
            i = right;
        }
        left = 2*i;
        right = 2*i+1;
    }
    if(left==size&&k>heap[left]){
        copy(&heap[i],&heap[left]);
        i = left;
    }
    copy(&heap[i],&k);
    return;
}
int delete_min_heap(int heap[],int *psize){
    int result = heap[1];
    copy(&heap[1],&heap[*psize]);
    *psize = *psize-1;
    restore_min_down(heap,1,*psize);
}


void restore_max_up(int heap[],int size){
    int i = size;
    int par = i/2;
    int k = heap[size];
    while(k>heap[par]){
        copy(&heap[i],&heap[par]);
        i = par;
        par = i/2;
    }
    copy(&heap[i],&k);
}
int push_max_heap(int heap[],int data,int *psize){
    *psize = *psize+1;
    heap[*psize] = data;
    restore_max_up(heap,*psize);
}
void restore_max_down(int heap[],int i,int size){
    int k = heap[i];
    int left = 2*i;
    int right = 2*i+1;
    while(right<=size){
        if(k>=heap[left]&&k>=heap[right]){
            copy(&heap[i],&k);
            return;
        }else if(heap[left]>heap[right]){
            copy(&heap[i],&heap[left]);
            i = left;
        }else{
            copy(&heap[i],&heap[right]);
            i = right;
        }
        left = 2*i;
        right = 2*i+1;
    }
    if(left==size&&k<heap[left]){
        copy(&heap[i],&heap[left]);
        i = left;
    }
    copy(&heap[i],&k);
    return;
}

int delete_max_heap(int heap[],int *psize){
    int result = heap[1];
    copy(&heap[1],&heap[*psize]);
    *psize = *psize-1;
    restore_max_down(heap,1,*psize);
}
int extract_Min(int min_heap[],int *psize){
    if(!is_empty(*psize)){
        return min_heap[1];
    }
    return min_heap[0];
}
int extract_Max(int max_heap[],int *psize){
    if(!is_empty(*psize)){
        return max_heap[1];
    }
    return max_heap[0];
}
int main() {
	//code
	int n;
	int input;
	int max_size = 0;
	int min_size = 0;
  double median = 0;
	initialize_heap(min_heap,max_heap);
 	for(int i=0;i<n;i++){
	    cin>>input;
      if(max_size==min_size){
        if(input>median){
          push_min_heap(min_heap,&min_size);
          median = (double)extract_Min(min_heap,&min_size);
        }else{
          push_max_heap(max_heap,&max_size);
          median = (double)extract_Max(max_heap,&max_size);
        }
      }else if(max_size>min_size){
        if(input>median){
          push_min_heap(min_heap,input,&min_size);
        }else{
          int data = delete_max_heap(max_heap,&max_size);
          push_min_heap(min_heap,data,&min_size);
          push_max_heap(max_heap,input,&max_size);
        }
        int m1 = extract_Max(max_heap,&max_size);
        int m2 = extract_Min(min_heap,&min_size);
        median = (double)(m1+m2)/2.0;
      }else{
        if(input>median){
          int data = delete_min_heap(min_heap,&min_size);
          push_min_heap(min_heap,data,&min_size);
          push_max_heap(max_heap,input,&max_heap);
        }else{
          push_max_heap(max_heap,input,&max_size);
        }
        int m1 = extract_Max(max_heap,&max_size);
        int m2 = extract_Min(min_heap,&min_size);
        median = (m1+m2)/2;
      }
      cout<<median<<" ";
	}
	return 0;
}
