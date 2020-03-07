#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */
void rearrange(struct Node *odd);
struct Node

{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
struct Node *start = NULL;
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");

}
void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        rearrange(start);
        printList(start);
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
  struct Node
  {
      int data;
      struct Node *next;

      Node(int x){
        data = x;
        next = NULL;
      }

   };
*/
struct Node *reverse(struct Node *start) {
	struct Node *ptr, *prev = NULL, *next;
	ptr = start;
	while (ptr != NULL) {
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}
void rearrange(struct Node *odd)
{
	//add code here
	struct Node *even = odd->next;
	struct Node *oddhead = odd;
	struct Node *evenhead = even;
	struct Node *tail = NULL;
	while (odd->next != NULL&&even->next != NULL) {
		if (even) {
			tail = odd;
			odd->next = even->next;
		}
		//if (odd)
			//odd = odd->next;
		odd = odd->next;
		if (odd) {
			even->next = odd->next;
		}

		//if (even)
		even = even->next;
	}
	//printList(evenhead);
	evenhead = reverse(evenhead);
	//printList(evenhead);
	if (odd == NULL) {
		tail->next = evenhead;
	}
	else {
		odd->next = evenhead;
	}
	odd = oddhead;
	//printList(odd);
}
