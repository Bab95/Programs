#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > graph;
void dfs(int i,vector<bool> &marked,int *c){
	marked[i] = true;
	*c = *c+1;
	vector<int>::iterator itr;
	for(itr=graph[i].begin();itr!=graph[i].end();itr++){
		if(!marked[*itr]){
			dfs(*itr,marked,c);
		}
	}
}
unsigned long long int solve(int v){
	vector<bool> marked(v,false);
	int count = 0;
	int *c = &count;
	vector<unsigned long long int> countries;
	for(int i=0;i<v;i++){
		if(!marked[i]){
			dfs(i,marked,c);
			countries.push_back(count);
			count = 0;
		}
	}
	unsigned long long int sum = 0;
	for(int i=0;i<countries.size();i++){
		sum+=countries[i];
	}
	unsigned long long int result = 0;
	for(int i=0;i<countries.size()-1;i++){
		sum = sum-countries[i];
		result+=countries[i]*sum;
	}
	return result;
}
int main(int argc, char *argv[]) {
	int v,e;
	cin>>v>>e;
	vector<int> tmp;
	for(int i=0;i<v;i++){
		graph.push_back(tmp);
	}
	int a,b;
	for(int i=0;i<e;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	unsigned long long int x = solve(v);
	cout<<x;

}
