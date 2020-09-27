#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* prev;
    node* next;
    node(int val):val(val),prev(NULL),next(NULL){}
};
node* convert2Bst(node* &head,int count){
    if(count<=0){
        return NULL;
    }
    node* left = convert2Bst(head,count/2);
    node* root = head;
    root->prev = left;
    head = head->next;
    root->next = convert2Bst(head,count-count/2-1);
    return root;
}
int countnodes(node* root){
    int res = 0;
    while(root){
        res++;
        root = root->next;
    }
    return res;
}
node* ConvertDLL2BST(node* root){
    int count = countnodes(root);
    return convert2Bst(root,count);
}
int main(){

}