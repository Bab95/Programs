#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void medianInstream(priority_queue<int>& max_heap,priority_queue<int,vector<int>,greater<int> >& min_heap,int input){
	    if(max_heap.size()==0){
	        //cout<<"c1"<<endl;
	        max_heap.push(input);
	        cout<<input<<" ";
	    }else if(max_heap.size()==min_heap.size()){
	        if(input<min_heap.top()){
	            //cout<<"c2.1"<<endl;
	            max_heap.push(input);
	            //cout<<max_heap.top()<<" ";

	        }else{
	            //cout<<"c2.2"<<endl;
	            int tmp = min_heap.top();
	            min_heap.pop();
	            min_heap.push(input);
	            max_heap.push(tmp);
	        }
	        cout<<max_heap.top()<<" ";
	    }else if(max_heap.size()>min_heap.size()){
	        if(input>max_heap.top()){
	            //cout<<"c3.1"<<endl;
	            min_heap.push(input);
	        }else{
	            //cout<<"c3.2"<<endl;
	            int tmp = max_heap.top();
	            max_heap.pop();
	            //cout<<"tmp: "<<tmp<<endl;
	            max_heap.push(input);
	            min_heap.push(tmp);
	        }
	        int median = (min_heap.top()+max_heap.top())/2;
	        cout<<median<<" ";
	    }
	cout<<endl;
}
int main() {
	//code
	int n;
	cin>>n;
	int input;priority_queue<int> max_heap;
	priority_queue<int,vector<int>,greater<int> > min_heap;
	for(int i=0;i<n;i++){
	    cin>>input;
	    medianInstream(max_heap,min_heap,input);
	}

	return 0;
}
