#include <string>
using namespace std;
#define A_SIZE 26
struct node{
    //int count;
    bool end;
    struct node *child[A_SIZE];
};
struct node *getnode(){
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    //tmp->count = 0;
    tmp->end = false;
    for(int i=0;i<A_SIZE;i++){
        tmp->child[i] = NULL;
    }
    return tmp;
}
int nochild(struct node *p,int *ind){
    int count = 0;
    for(int i=0;i<A_SIZE;i++){
        if(p->child[i]!=NULL){
            count++;
            *ind = i;
        }
    }
    return count;
}
void insert(struct node *root,string s){
    struct node *p = root;
    for(int i=0;i<s.length();i++){
        int index =(int)s[i]-97;
        if(p->child[index]==NULL){
            p->child[index] = getnode();
            //p->child[index]->count = 1;
        }/*else{
            p->child[index]->count+=1;
        }*/
        p = p->child[index];
    }
    p->end = true;
}
string longestprefix(struct node *p,bool *flag){
    string s;
    int i = 0;
    while(nochild(p,&i)==1&&!p->end){
        s.push_back((char)(i+97));
        p = p->child[i];
        *flag = true;
    }
    return s;
}
int main() {
	//code
	int t;
	cin>>t;
	int n;
	struct node *root = NULL;
	while(t--){
	    cin>>n;
	    string s;
	    root = getnode();
	    for(int i=0;i<n;i++){
	        cin>>s;
	        insert(root,s);
	    }
	    bool flag = false;
	    s = longestprefix(root,&flag);
	    if(flag){
	        cout<<s<<endl;
	    }else{
	        cout<<"-1"<<endl;
	    }
	}
	return 0;
}
