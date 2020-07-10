/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void printlist(Node* list){
        while(list!=NULL){
            cout<<list->val<<" ";
            list = list->next;
        }
        cout<<endl;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* current = head;
        //copying with normal pointers.....
        while(current!=NULL){
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }
        Node* head2 = NULL;
        //head2 = head->next;
        //Node* q = head2;
        Node* q = NULL;
        current = head;
        //populating random....
        printlist(head);
        while(current!=NULL){
            if(current->random==NULL){
                current = current->next->next;
                continue;
            }
            current->next->random = current->random->next;
            current = current->next->next;
        }
        //separating.....
        current = head;
        while(current!=NULL){
            Node* tmp = current->next->next;
            if(head2==NULL){
                head2 = current->next;
                q = head2;
            }else{
                q->next = current->next;
                q = q->next;
            }
            current->next = tmp;
            current = current->next;
        }
        return head2;
    }
};
