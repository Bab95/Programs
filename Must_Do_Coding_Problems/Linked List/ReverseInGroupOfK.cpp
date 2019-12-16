#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct node *reverse (struct node *head, int k);
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};
/* UTILITY FUNCTIONS */
/* Function to push a node */
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
     int t;
     cin>>t;

     while(t--)
     {
         struct node* head = NULL;
         struct node* temp = NULL;
         int n;
         cin >> n;

         for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
         }

        int k;
        cin>>k;
        head = reverse(head, k);
        printList(head);

     }

     return(0);
}

/*This is a function problem.You only need to complete the function given below*/

struct node *reverse (struct node *head, int k)
{
    // Complete this method
    if(k==1){
        return head;
    }
    struct node* ptr;
    ptr=head;
    struct node* next=NULL;
    struct node* prev = NULL;
    int i=0;
    while(ptr!=NULL&&i<k){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
        i++;
    }
    if(next!=NULL){
        head->next = reverse(next,k);

    }
    return prev;
}
