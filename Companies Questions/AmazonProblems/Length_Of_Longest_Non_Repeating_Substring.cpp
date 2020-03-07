#include <iostream>
#include <string>
#define CHARS 256
using namespace std;
void memset(int arr[],int value,int size){
    for(int i=0;i<size;i++){
        arr[i] = value;
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int current_length = 1;
	    int max_length = 1;
	    int previous_index;
	    int visited_last[CHARS];
	    memset(visited_last,-1,CHARS);
	    visited_last[s[0]] = 0;
	    for(int i=1;i<s.length();i++){
	        previous_index = visited_last[s[i]];
	        if(previous_index==-1||i-current_length>previous_index){
	            current_length++;
	        }else{
	            if(max_length<current_length){
	                max_length = current_length;
	            }
	            current_length = i-previous_index;
	        }
	        visited_last[s[i]] = i;
	    }
	    if(current_length>max_length){
	        max_length = current_length;
	    }
	    cout<<max_length<<endl;
	}
	return 0;
}
