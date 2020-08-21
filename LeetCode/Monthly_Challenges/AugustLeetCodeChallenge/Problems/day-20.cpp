/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* node){
        ListNode *prev = NULL,*next = NULL,*ptr = node;
        while(ptr){
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        node = prev;
        return node;
    }
    void print(ListNode* p){
        while(p!=NULL){
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return;
        }
        ListNode *p = head,*q = head;
        while(q!=NULL&&q->next!=NULL&&q->next->next!=NULL){
            p = p->next;
            q = q->next->next;
        }
        ListNode *mid = p->next;
        p->next = NULL;
        print(head);

        mid = reverse(mid);
        print(mid);
        p = head;
        head = NULL;
        q = NULL;
        while(p&&mid){
            if(head==NULL){
                head = p;
                p = p->next;
                q = head;
                q->next = mid;
                mid = mid->next;
                q = q->next;
            }else{
                q->next = p;
                p = p->next;
                q = q->next;
                q->next = mid;
                mid = mid->next;
                q = q->next;
            }
        }
        if(p!=NULL){
            q->next = p;
        }
    }
};
/*

1 2 3 4 5 6
p
q
  p q
    p   q




*/
