#include <iostream>
#include <vector>
using namespace std;
void swap(pair<int,int> &v1,pair<int,int> &v2){
    pair<int,int> tmp;
    tmp.first = v1.first;
    tmp.second = v1.second;
    v1.first = v2.first;
    v1.second = v2.second;
    v2.first = tmp.first;
    v2.second = tmp.second;
    return;
}
int partition(vector<pair<int,int> > &plates,int start,int end){
    pair<int,int> pivot = plates[start];
    int i = start+1;
    for(int j=start+1;j<=end;j++){
        if(plates[j].second>pivot.second){
            swap(plates[i],plates[j]);
            i++;
        }
    }
    swap(plates[i-1],plates[start]);
    return i-1;
}
void quicksort(vector<pair<int,int> > &plates,int start,int end){
    if(start<end){
        int pivot = partition(plates,start,end);
        quicksort(plates,start,pivot-1);
        quicksort(plates,pivot+1,end);
    }
}
int main() {
	//code
	int t,nT,N;
	cin>>t;
	while(t--){
	    cin>>nT>>N;
	    vector<pair<int,int> > plates(N);
	    for(int i=0;i<N;i++){
	        cin>>plates[i].first>>plates[i].second;
	    }
	    quicksort(plates,0,N-1);
	    /*for(int i=0;i<N;i++){
	        cout<<plates[i].first<<" "<<plates[i].second<<endl;
	    }*/
	    int result = 0;
	    int done = 0;
	    for(int i=0;i<N;i++){
	        if(done+plates[i].first<=nT){
	            done+=plates[i].first;
	            int coins = plates[i].first*plates[i].second;
	            result+=coins;
	        }else{
	           int left = nT-done;
	           int coins = left*plates[i].second;
	           result+=coins;
	           done+=left;
	           if(done==nT){
	               break;
	           }
	        }
	    }
	    cout<<result<<endl;
	}
	return 0;
}
