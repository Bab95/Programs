/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void split(ListNode *head, ListNode **a,ListNode **b){
        ListNode *slow = head,*fast=(head->next);
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
        return;
    }
    ListNode *reverse(ListNode *head){
        ListNode *ptr = head,*prev = NULL,*next;
        while(ptr!=NULL){
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        head = prev;
        return head;
    }
    ListNode *combine(ListNode *a,ListNode *b){
        ListNode *result = NULL,*q = NULL;
        ListNode *tmp = NULL;
        //cout<<"in combine function"<<endl;
        while(a!=NULL||b!=NULL){
            if(result==NULL){
                tmp = a->next;
                a->next = NULL;
                result = a;
                a = tmp;

                tmp = b->next;
                b->next = NULL;
                result->next = b;
                b = tmp;
                q = result->next;
            }else{
                tmp = a->next;
                a->next = NULL;
                q->next = a;
                a = tmp;
                q = q->next;
                if(b!=NULL){
                    tmp = b->next;
                    b->next = NULL;
                    q->next = b;
                    b = tmp;
                    q = q->next;
                }

            }


        }
        //cout<<"out combine function"<<endl;
        return result;

    }
    void printList(ListNode *p){
        while(p!=NULL){
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    void reorderList(ListNode* head) {
        if(head!=NULL&&head->next!=NULL){
            ListNode *h1 = NULL,*h2 = NULL;
            split(head,&h1,&h2);
            //printList(h1);
            //printList(h2);
            h2 = reverse(h2);
            //printList(h2);
            head = combine(h1,h2);
            //cout<<"final output"<<endl;
            //printList(head);
        }
    }
};
