#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct Node* addTwoLists(struct Node* first, struct Node* second);
void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("
");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
// write a function returns the resultant linked list
Node* getnode(int data){
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data =data;
    tmp->next = NULL;
    return tmp;
}
Node* addTwoLists(Node* first, Node* second) {
    Node* result = NULL;
    Node* q = NULL;
    Node* tmp;
    int carry = 0;
    int sum = 0,rem = 0;
    while(first||second){
        sum = (first?first->data:0)+(second?second->data:0)+carry;
        tmp = getnode(sum%10);
        carry = sum/10;
        if(result==NULL){
            result = tmp;
        }else{
            q->next = tmp;
        }
        if(first){
            first = first->next;
        }
        if(second){
            second = second->next;

        }
        q = tmp;
    }
    if(carry>0){
        q->next = getnode(carry);
    }
   return result;
}
