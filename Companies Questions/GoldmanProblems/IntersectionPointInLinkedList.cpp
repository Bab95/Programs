#include<iostream>
#include<stdio.h>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
int intersectPoint(struct Node* head1, struct Node* head2);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
int length(Node* root){
    int count = 0;
    while(root!=NULL){
        root = root->next;
        count++;
    }
    return count;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int l1 = length(head1);
    int l2 = length(head2);
    int k = (l1>l2)?(l1-l2):(l2-l1);
    Node *p = (l1>l2)?head1:head2;
    Node *q = (l1>l2)?head2:head1;
    while(k>0){
        p = p->next;
        k--;
    }
    while(p!=NULL&&q!=NULL){
        if(p->data==q->data&&p==q){
            return p->data;
        }
        p = p->next;
        q = q->next;
    }
    return -1;
}
