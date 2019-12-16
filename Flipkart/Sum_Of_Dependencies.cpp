#include <iostream>
#include <vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	int n,e;
	while(t--){
	    cin>>n>>e;
	    vector<vector<int> > graph;
	    vector<int> tmp;
	    for(int i=0;i<n;i++){
	        graph.push_back(tmp);
	    }
	    int src,dst;
	    for(int i=0;i<e;i++){
	        cin>>src>>dst;
	        graph[dst].push_back(src);
	    }
	    int score = 0;
	    for(int i=0;i<n;i++){
	        score+=graph[i].size();
	    }
	    cout<<score<<endl;
	}
	return 0;
}
