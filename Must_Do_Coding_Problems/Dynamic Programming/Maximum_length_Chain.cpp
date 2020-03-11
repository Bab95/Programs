// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}

		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int max(int a,int b){
    return a>b?a:b;
}
void swap(struct val *p1,struct val* p2){
    struct val p3;
    p3.first = p1->first;
    p3.second = p1->second;
    p1->first = p2->first;
    p1->second = p2->second;
    p2->first = p3.first;
    p2->second = p3.second;
    return;
}
int partition(struct val p[],int start,int end){
    int pivot = p[start].first;
    int i = start+1;
    for(int j=start+1;j<=end;j++){
        if(p[j].first<pivot){
            swap(&p[i],&p[j]);
            i++;
        }
    }
    swap(&p[i-1],&p[start]);
    return i-1;
}
void sortstructs(struct val p[],int start,int end){
    if(start<end){
        int pivot = partition(p,start,end);
        sortstructs(p,start,pivot-1);
        sortstructs(p,pivot+1,end);
    }
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    int lis[n];
    for(int i=0;i<n;i++){
        lis[i] = 1;
    }
    //lis[0] = 1;
    int max_length = 1;
    sortstructs(p,0,n-1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[i].first>p[j].second&&lis[i]<lis[j]+1){
                lis[i] = lis[j]+1;
                max_length = max(max_length,lis[i]);
            }
        }
    }
    return max_length;
}
