#include <iostream>
#include <vector>
using namespace std;
struct meeting{
    int start;
    int end;
    int index;
};
void swap(struct meeting *t1,struct meeting *t2){
    int s = t1->start;
    int e = t1->end;
    int i = t1->index;
    t1->start = t2->start;
    t1->end = t2->end;
    t1->index = t2->index;
    t2->start = s;
    t2->end = e;
    t2->index = i;
    return;
}
int partition(struct meeting meetings[],int start,int end){
    int pivot = meetings[start].end;
    int i = start+1;
    for(int j=start+1;j<=end;j++){
        if(meetings[j].end<pivot){
            swap(&meetings[i],&meetings[j]);
            i++;
        }
    }
    swap(&meetings[i-1],&meetings[start]);
    return i-1;
}
void quicksort(struct meeting meetings[],int start,int end){
    if(start<end){
        int pivot = partition(meetings,start,end);
        quicksort(meetings,start,pivot-1);
        quicksort(meetings,pivot+1,end);
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
	    struct meeting meetings[n];
	    for(int i=0;i<n;i++){
	        cin>>meetings[i].start;
	        meetings[i].index = i+1;
	    }
	    for(int i=0;i<n;i++){
	        cin>>meetings[i].end;
	    }
	    quicksort(meetings,0,n-1);
	    vector<int> current_meetings;
      current_meetings.push_back(meetings[0].index);
      int time_limit = meetings[0].end;

      for(int i=1;i<n;i++){
        if(meetings[i].start>=time_limit){
          current_meetings.push_back(meetings[i].index);
          time_limit = meetings[i].end;
        }
      }
      for(int i=0;i<current_meetings.size();i++){
          cout<<current_meetings[i]<<" ";
      }
      cout<<endl;
	}
	return 0;
}
