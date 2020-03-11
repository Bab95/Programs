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
    ListNode* reverse(ListNode *head,ListNode **tail){
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next;
        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *tail = head;
        head = prev;
        return head;
    }
    int length(ListNode* head){
        int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    int abs(int a){
        if(a<0){
            return -1*a;
        }
        return a;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int la = length(headA);
        int lb = length(headB);
        if(la==0||lb==0){
            return NULL;
        }
        /*if(la==1||lb==1){
            ListNode* result = (la==1)?headA:headB;
            return result;
        }*/
        ListNode *small,*large;
        if(la<lb){
            small = headA;
            large = headB;
        }else{
            small = headB;
            large = headA;
        }
        int k = abs(la-lb);
        while(k--){
            large = large->next;
        }
        //ListNode* prev = small;
        while(small!=NULL&&large!=NULL){
            //prev = small;
            if(small==large){
                return small;
            }
            small = small->next;
            large = large->next;
        }
        return NULL;
    }
};
