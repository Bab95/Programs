/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* result = head;
        stack<Node*> stk;
        Node* p = head;
        while(p->next==NULL){
            if(p->child!=NULL){
                p->next = p->child;
                p->next->prev = p;
                p->child = NULL;
                p = p->next;
            }else{
                break;
            }
        }
        while(p->next!=NULL||!stk.empty()){
            if(p->next==NULL){
                p->next = stk.top();
                stk.pop();
                p->next->prev = p;
            }
            if(p->child!=NULL){
               if(p->next!=NULL){
                   p->next->prev = NULL;
                   Node* tmp = p->next;
                   p->next = p->child;
                   p->child = NULL;
                   p->next->prev = p;
                   stk.push(tmp);
               }else{
                   p->next = p->child;
                   p->next->prev = p;
               }
                p = p->next;
            }else{
                p = p->next;
            }
        }
        return result;
    }
};
/*
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
[1,2,null,3]
[1,null,2,null,3,null,4]
*/
