#include <iostream>
#include <string.h>
using namespace std;
struct task{
    int start;
    int end;
};
void swap(struct task *t1,struct task *t2){
    int s = t1->start;
    int e = t1->end;
    t1->start = t2->start;
    t1->end = t2->end;
    t2->start = s;
    t2->end = e;
    return;
}
int partition(struct task tasks[],int start,int end){
    int pivot = tasks[start].start;
    int i = start+1;
    for(int j=start+1;j<=end;j++){
        if(tasks[j].start<pivot){
            swap(&tasks[i],&tasks[j]);
            i++;
        }
    }
    swap(&tasks[i-1],&tasks[start]);
    return i-1;
}
void quicksort(struct task tasks[],int start,int end){
    if(start<end){
        int pivot = partition(tasks,start,end);
        quicksort(tasks,start,pivot-1);
        quicksort(tasks,pivot+1,end);
    }
}
int max(int a,int b){
    return a>b?a:b;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int start[n];
	    int end[n];
	    struct task tasks[n];
	    for(int i=0;i<n;i++){
	        cin>>tasks[i].start;
	    }
	    for(int i=0;i<n;i++){
	        cin>>tasks[i].end;
	    }
	    quicksort(tasks,0,n-1);
	    int aselection[n];
	    aselection[0] = 1;
	    int result = 1;
	    for(int i=1;i<n;i++){
	        aselection[i] = 1;
	        for(int j=0;j<i;j++){
	            if((tasks[i].start>=tasks[j].end)&&(aselection[i]<aselection[j]+1)){
	                aselection[i] = aselection[j]+1;
	                result = max(result,aselection[i]);
	            }
	        }
	    }
	    cout<<result<<endl;
    }
	return 0;
}
