/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* getnode(int data){
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->val = data;
    tmp->next = NULL;
    return tmp;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = NULL;
    struct ListNode* q = NULL;
    int carry = 0,sum=0;
    while(l1||l2){
      int sum = ((l1==NULL)?0:l1->val)+((l2==NULL)?0:l2->val)+carry;
      if(result==NULL){
          result = getnode(sum%10);
          q = result;
      }else{
          q->next = getnode(sum%10);
          q = q->next;
      }
      carry = sum/10;
      l1 = (l1==NULL)?NULL:l1->next;
      l2 = (l2==NULL)?NULL:l2->next;
    }
    if((!l1&&!l2)&&(carry!=0)){
        q->next = getnode(carry);
    }
    return result;
}
