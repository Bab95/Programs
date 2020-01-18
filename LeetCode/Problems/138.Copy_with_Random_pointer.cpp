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

/*Link:https://leetcode.com/problems/copy-list-with-random-pointer/*/
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
         Node* p = head;
        while(p!=NULL){
            Node* newNode = new Node(p->val);
            Node* tmp = p->next;
            newNode->next = p->next;
            p->next = newNode;
            p = tmp;
        }
        //printlist(head);
        Node* original = NULL;
        Node* copy = NULL;
        original = head;
        copy = (head!=NULL)?head->next:NULL;
        while(original&&copy){
            if(original&&original->random){
                copy->random = original->random->next;
            }
            original = copy->next;
            if(original){
                copy = original->next;
            }
        }
        original = head;
        copy = (head!=NULL)?head->next:NULL;
        Node* result = NULL;
        result = copy;
        while(original){
            original->next = copy->next;
            original = original->next;
            copy->next = (original!=NULL)?original->next:NULL;
            copy = copy->next;
        }
        //printlist(head);
        //printlist(result);
        return result;
    }
};
