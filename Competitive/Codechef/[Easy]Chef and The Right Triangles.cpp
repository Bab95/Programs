#include <iostream>

using namespace std;
int dist(int x1,int y1,int x2,int y2){
	int a = (x2-x1);
	int b = (y2-y1);
	return (a*a)+(b*b);
}
int maximum(int a,int b,int c){
	return a>b?(a>c?a:c):(b>c?b:c);
}
int main(int argc, char *argv[]) {
	int n;
	int a,b,c,d,e,f;
	int count = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c>>d>>e>>f;
		int x = dist(a,b,c,d);
		int y = dist(c,d,e,f);
		int z = dist(e,f,a,b);
		if(2*maximum(x,y,z)==x+y+z){
			count++;
			//cout<<x<<" "<<y<<" "<<z<<endl;
		}
	}
	cout<<count<<endl;
}
